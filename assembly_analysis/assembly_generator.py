import sys
sys.path.append('./analyzers')

import numpy as np
import random
import re
import os
import concurrent.futures

from instruction_analyzer import InstructionAnalyzer
from data_dependency_analyzer import DataDependencyAnalyzer
from dcache_analyzer import DCacheAnalyzer
from icache_analyzer import ICacheAnalyzer
from branch_analyzer import BranchAnalyzer
from inst_mix_analyzer import InstMixAnalyzer

BASE_ARITH_INT_OPS = ['and', 'or', 'sub', 'add']
BASE_ARITH_FP_OPS = ['fadd', 'fsub']
SSE_ARITH_FP_OPS = ['addsd', 'subsd']
BASE_MUL_INT_OPS = ['mul', 'imul']
BASE_MUL_FP_OPS = ['fmul']
SSE_MUL_FP_OPS = ['mulsd']
BASE_DIV_INT_OPS = ['div', 'idiv']
BASE_DIV_FP_OPS = ['fdiv']
SSE_DIV_FP_OPS = ['divsd']

BASE_ADDR_REG = 'r8'
TOP_ADDR_REG = 'r9'
ADDR_OFFSET_REG = 'r10'
LOOP_IDX_REG = 'r11'
RAND_REG = 'r12'
POINTER_CHASE_REG = 'r13'

RAND_A = 1103515245
RAND_C = 12345

CACHELINE_SIZE = 64
CACHELINE_OFFSET = int(np.log2(CACHELINE_SIZE))
PAGE_SIZE = 4096
PAGE_OFFSET = int(np.log2(PAGE_SIZE))

GP_REG_NAMES = [
    'a', 'b', 'c', 'd', 'sp', 'bp', 'si', 'di', 'r8', 'r9', 'r10', 'r11', 'r12', 'r13', 'r14', 'r15']

XMM_REGS = [f'xmm{i}' for i in range(32)]
YMM_REGS = [f'ymm{i}' for i in range(32)]
ST_REGS = [f'st({i})' for i in range(8)]
CLOG_REGS = [ADDR_OFFSET_REG, LOOP_IDX_REG, RAND_REG, POINTER_CHASE_REG, 'sp', 'bp', 'xmm1', 'st(1)']

def reg(reg, size):
  if reg.startswith('xmm') or reg.startswith('ymm') or reg.startswith('st'):
    return reg
  assert size in [8, 16, 32, 64]
  assert reg in ['a', 'b', 'c', 'd', 'sp', 'bp', 'si', 'di',
                 'r8', 'r9', 'r10', 'r11', 'r12', 'r13', 'r14', 'r15']
  if size == 8:
    if reg in ['a', 'b', 'c', 'd', 'sp', 'bp', 'si', 'di']:
      return f'{reg}l'
    else:
      return f'{reg}b'
  elif size == 16:
    if reg in ['a', 'b', 'c', 'd']:
      return f'{reg}x'
    elif reg in ['sp', 'bp', 'si', 'di']:
      return reg
    else:
      return f'{reg}w'
  elif size == 32:
    if reg in ['a', 'b', 'c', 'd']:
      return f'e{reg}x'
    elif reg in ['sp', 'bp', 'si', 'di']:
      return f'e{reg}'
    else:
      return f'{reg}d'
  else:
    if reg in ['a', 'b', 'c', 'd']:
      return f'r{reg}x'
    elif reg in ['sp', 'bp', 'si', 'di']:
      return f'r{reg}'
    else:
      return f'{reg}'

def rightRotate(n, d):
	return (n >> d)|(n << (32 - d)) & 0xFFFFFFFF

def get_tids(sde_path):
  tids = []
  f = open(os.path.join(sde_path, 'sde-mix-out.txt'), 'r')
  lines = f.readlines()
  for line in lines:
    if '# Starting tid' in line:
      tids.append(int(line.split(' ')[3][:-1]))
    if '# FINI: end of program' in line:
      break
  return tids

class AssemblyGenerator:

  def __init__(self, app, skeleton, sde_total_reqs,
      input_path, app_tids, skeleton_tids, 
      min_dcache_size, max_dcache_size, min_icache_size, max_icache_size,
      num_reqs_per_iteration=1<<10, num_block_replicas={}, 
      page_multiplier=1, pointer_chase_rate=0, num_asm_functions=1, 
      num_reps=-1, num_dynamic_insts=-1, 
      hard_branch_rate=0, icache_stats=None, dcache_stats=None,
      branch_stats=None, debug=False, profiling=True):
    self.app = app
    self.skeleton = skeleton
    self.sde_total_reqs = sde_total_reqs
    self.input_path = input_path
    self.app_tids = app_tids
    self.skeleton_tids = skeleton_tids
    self.num_reqs_per_iteration = num_reqs_per_iteration
    self.num_block_replicas = num_block_replicas
    self.num_asm_functions = num_asm_functions
    self.debug = debug
    self.max_dcache_size = max_dcache_size
    self.max_icache_size = max_icache_size
    self.min_dcache_size = min_dcache_size
    self.min_icache_size = min_icache_size
    self.page_multiplier = page_multiplier
    self.hard_branch_rate = hard_branch_rate
    self.pointer_chase_rate = pointer_chase_rate

    self.br_cond_label_idx = {}
    self.br_uncond_label_idx = {}

    # # If tids not specified, use all tids though this may cause inaccurate results
    # if not app_tids:
    #   self.app_tids = get_tids(os.path.join(self.input_path, f'{app}', 'sde'))
    # if not skeleton_tids:
    #   self.skeleton_tids = get_tids(os.path.join(self.input_path, f'{skeleton}', 'sde'))

    if profiling:
      branch_analyzer = BranchAnalyzer(
          app=self.app,
          skeleton=self.skeleton,
          input_path=self.input_path,
          app_tids=self.app_tids,
          skeleton_tids=self.skeleton_tids,
          ignore_transition=True
      )
      data_dependency_analyzer = DataDependencyAnalyzer(
          app=self.app,
          skeleton=self.skeleton,
          input_path=self.input_path,
          app_tids=self.app_tids,
          skeleton_tids=self.skeleton_tids,
          max_bb_depth=64,
          bins=[1, 2, 4, 8, 16, 32, 64, 128, 256],
      )
      dcache_analyzer = DCacheAnalyzer(
          associativity=8,
          exclude=False,
          source='valgrind',
          app=self.app,
          skeleton=self.skeleton,
          input_path=self.input_path,
          app_tids=self.app_tids,
          skeleton_tids=self.skeleton_tids,
          max_size=self.max_dcache_size,
          min_size=self.min_dcache_size
      )
      icache_analyzer = ICacheAnalyzer(
          associativity=8,
          exclude=False,
          app=self.app,
          skeleton=self.skeleton,
          input_path=self.input_path,
          app_tids=self.app_tids,
          skeleton_tids=self.skeleton_tids,
          max_size=self.max_icache_size,
          min_size=self.min_icache_size,

      )
      inst_mix_analyzer = InstMixAnalyzer(
          app=self.app,
          skeleton=self.skeleton,
          input_path=self.input_path,
          app_tids=self.app_tids,
          skeleton_tids=self.skeleton_tids
      )
      instruction_analyzer = InstructionAnalyzer(
          app=self.app,
          skeleton=self.skeleton,
          input_path=self.input_path,
          app_tids=self.app_tids,
          skeleton_tids=self.skeleton_tids,
          total_reqs=self.sde_total_reqs
      )

      self.branch_stats = branch_analyzer.run_analysis()
      self.data_dependency_distribution = data_dependency_analyzer.run_analysis()
      self.dcache_stats = dcache_analyzer.run_analysis()
      self.icache_stats = icache_analyzer.run_analysis()
      self.imix_hist, self.ldst_hist = inst_mix_analyzer.run_analysis()
      self.instruction_info = instruction_analyzer.run_analysis()
      if num_reps == -1:
        self.num_reps = self.instruction_info["rep_num_dynamic_insts_per_request"]
      else:
        self.num_reps = num_reps
      if num_dynamic_insts == -1:
        self.num_dynamic_insts = self.instruction_info["num_dynamic_insts_per_request"]
      else:
        self.num_dynamic_insts = num_dynamic_insts

    else:
      self.dcache_stats = dcache_stats
      self.icache_stats = icache_stats
      self.branch_stats = branch_stats
      self.inst_mix_analyzer = InstMixAnalyzer(
          app=self.app,
          skeleton=self.skeleton,
          input_path=self.input_path,
          app_tids=self.app_tids,
          skeleton_tids=self.skeleton_tids
      )
      self.data_dependency_analyzer = DataDependencyAnalyzer(
          app=self.app,
          skeleton=self.skeleton,
          input_path=self.input_path,
          app_tids=self.app_tids,
          skeleton_tids=self.skeleton_tids,
          max_bb_depth=64,
          bins=[1, 2, 4, 8, 16, 32, 64, 128, 256],
      )
      self.imix_hist, self.ldst_hist = self.inst_mix_analyzer.run_analysis()
      self.data_dependency_distribution = self.data_dependency_analyzer.run_analysis()

    self.mean_inst_size = 4
    self.base_mem_addr = 0

  def set_icache_stats(self, icache_stats):
    self.icache_stats = icache_stats

  def __branch_bit_mask(self, taken_rate, transition_rate):
    if taken_rate == 0 or taken_rate == 1:
      return (1 << 32) - 1
    elif taken_rate >= 0.5:
      num_ones = int(abs(np.round(np.log2((1 - taken_rate)))))
    else:
      num_ones = int(abs(np.round(np.log2((taken_rate)))))
    if transition_rate == 0:
      num_zeros = 0
    else:
      num_zeros = int(np.log2((1 / transition_rate * taken_rate * 2)))
    return min(int('1' * num_ones + '0' * num_zeros, base=2), (1 << 32) - 1)

  def __asm_inst_generator(self, op_type, function_id, block_id, replica_id):
    # Generate a random instruction

    # ================================================================
    # Arithmetic instruction
    # ================================================================
    if op_type == 'base.arith.int.mem_r':
      op = random.choice(BASE_ARITH_INT_OPS)
      # return f'"{op} <X_REG>, QWORD PTR[{reg(POINTER_CHASE_REG, 64)}]\\n"\n'
      return f'"{op} <X_REG>, QWORD PTR[<MEMADDR>]\\n"\n'
      # return f'"nop\\n"\n'
    elif op_type == 'base.arith.int.mem_x' or op_type == 'sse.arith.int.mem_x':
      op = random.choice(BASE_ARITH_INT_OPS)
      return f'"{op} QWORD PTR[<MEMADDR>], <R_REG>\\n"\n'
    elif op_type == 'base.arith.int.no_mem':
      op = random.choice(BASE_ARITH_INT_OPS)
      return f'"{op} <X_REG>, <R_REG>\\n"\n'
    elif op_type in ['base.arith.fp.mem_r', 'sse.arith.int.mem_r', 'avx.arith.fp.mem_r', 'sse.arith.fp.mem_r']:
      op = random.choice(SSE_ARITH_FP_OPS)
      return f'"{op} <X_XMMREG>, QWORD PTR[<MEMADDR>]\\n"\n'
    elif op_type in ['base.arith.fp.no_mem', 'sse.arith.int.no_mem', 'avx.arith.fp.no_mem', 'sse.arith.fp.no_mem']:
      op = random.choice(SSE_ARITH_FP_OPS)
      return f'"{op} <X_XMMREG>, <R_XMMREG>\\n"\n'
    
    # ================================================================
    # Mul instruction
    # ================================================================
    elif op_type == 'base.mul.int.mem_r':
      op = random.choice(BASE_MUL_INT_OPS)
      return f'"{op} QWORD PTR[<MEMADDR>]\\n"\n'
    elif op_type == 'base.mul.int.no_mem':
      op = random.choice(BASE_MUL_INT_OPS)
      return f'"{op} <R_REG>\\n"\n'
    elif op_type == 'base.mul.fp.no_mem':
      op = random.choice(BASE_MUL_FP_OPS)
      return f'"{op} st(0), <R_STREG>\\n"'
    elif op_type == 'base.mul.fp.mem_r':
      op = random.choice(BASE_MUL_FP_OPS)
      return f'"{op} st(0), QWORD PTR[<MEMADDR>]\\n"\n'
    elif op_type == 'sse.mul.fp.mem_r':
      op = random.choice(SSE_MUL_FP_OPS)
      return f'"{op} <X_XMMREG>, QWORD PTR[<MEMADDR>]\\n"\n'
    elif op_type == 'sse.mul.fp.no_mem':
      op = random.choice(SSE_MUL_FP_OPS)
      return f'"{op} <X_XMMREG>, <R_XMMREG>\\n"\n'

    # ================================================================
    # Div instruction
    # TODO: MUL FOR NOW
    # ================================================================
    # Assert memory base address register is not zero.
    # Cannot use mem_r since it cannot be asserted to be non-zero,
    # replace it with register.
    if op_type == 'base.div.int.mem_r' or op_type == 'base.div.int.no_mem':
      op = random.choice(BASE_MUL_INT_OPS)
      return f'"{op} <R_REG>\\n"\n'
    # Assert xmm1 register is not zero.
    elif op_type == 'sse.div.fp.mem_r' or op_type == 'sse.div.fp.no_mem':
      op = random.choice(SSE_MUL_FP_OPS)
      return f'"{op} <X_XMMREG>, QWORD PTR[<MEMADDR>]\\n"\n'
    # Assert st(1) is not zero.
    elif op_type == 'base.div.fp.mem_r' or op_type == 'base.div.fp.no_mem':
      op = random.choice(BASE_MUL_FP_OPS)
      return f'"{op} st(0), <R_STREG>\\n"'
    
    # ================================================================
    # Branch instruction
    # ================================================================
    elif op_type in ['base.branch.uncond.mem_r', 'base.branch.uncond.no_mem']:
      asm = (f'"jmp br_uncond_func_{function_id}_block_{block_id}_rep_{replica_id}_{self.br_uncond_label_idx[function_id][block_id][replica_id]}\\n"\n'
             f'"br_uncond_func_{function_id}_block_{block_id}_rep_{replica_id}_{self.br_uncond_label_idx[function_id][block_id][replica_id]}:"\n')
      self.br_uncond_label_idx[function_id][block_id][replica_id] += 1
      return asm
    elif op_type in ['base.branch.cond.mem_r', 'base.branch.cond.no_mem']:
      taken_rate, transition_rate = random.choices(
          population=list(self.branch_stats.keys()),
          weights=list(self.branch_stats.values()),
          k=1)[0]
      bit_mask = self.__branch_bit_mask(taken_rate, transition_rate)
      hard_branch_flag = np.random.binomial(1, self.hard_branch_rate)
      taken = 0
      if hard_branch_flag == 0:
        if taken >= 0.5:
          asm = (
                f'"test {reg(LOOP_IDX_REG, 32)}, {bit_mask}\\n"\n'
                f'"jnz br_cond_func_{function_id}_block_{block_id}_rep_{replica_id}_{self.br_cond_label_idx[function_id][block_id][replica_id]}\\n"\n'
                f'"br_cond_func_{function_id}_block_{block_id}_rep_{replica_id}_{self.br_cond_label_idx[function_id][block_id][replica_id]}:"\n')
        else:
          bit_mask = 1 << random.randint(0, 31)
          asm = (
                f'"test {reg(LOOP_IDX_REG, 32)}, {bit_mask}\\n"\n'
                f'"jz br_cond_func_{function_id}_block_{block_id}_rep_{replica_id}_{self.br_cond_label_idx[function_id][block_id][replica_id]}\\n"\n'
                f'"br_cond_func_{function_id}_block_{block_id}_rep_{replica_id}_{self.br_cond_label_idx[function_id][block_id][replica_id]}:"\n')
      else:
        bit_mask = rightRotate(bit_mask, random.randint(0, 31))
        asm = (
                f'"test {reg(RAND_REG, 32)}, {bit_mask}\\n"\n'
                f'"jz br_cond_func_{function_id}_block_{block_id}_rep_{replica_id}_{self.br_cond_label_idx[function_id][block_id][replica_id]}\\n"\n'
                f'"br_cond_func_{function_id}_block_{block_id}_rep_{replica_id}_{self.br_cond_label_idx[function_id][block_id][replica_id]}:"\n')

      self.br_cond_label_idx[function_id][block_id][replica_id] += 1
      return asm
    
    # ================================================================
    # Move instruction
    # ================================================================
    elif op_type in ['base.mov.uncond.mem_r', 'base.mov.cond.mem_r']:
      pointer_chase_flag = np.random.binomial(1, self.pointer_chase_rate, 1)[0]
      if pointer_chase_flag == 1:
        return f'"mov {reg(POINTER_CHASE_REG, 64)}, QWORD PTR[{reg(POINTER_CHASE_REG, 64)}]\\n"\n'
      else:
        return '"mov <W_REG>, QWORD PTR[<MEMADDR>]\\n"\n'
    elif op_type in ['base.mov.uncond.mem_w', 'base.mov.cond.mem_w']:
      return '"mov QWORD PTR[<MEMADDR>], <R_REG>\\n"\n'
    elif op_type in ['base.mov.uncond.no_mem', 'base.mov.cond.no_mem']:
      return '"mov <W_REG>, <R_REG>\\n"\n'
    elif op_type in ['base.mov.cond.mem_r']:
      return '"cmovz <W_REG>, QWORD PTR[<MEMADDR>]\\n"\n'
    elif op_type in ['base.mov.cond.mem_w']:
      return '"cmovz QWORD PTR[<MEMADDR>], <R_REG>\\n"\n'
    elif op_type in ['base.mov.cond.no_mem']:
      return '"cmovz <W_REG>, <R_REG>\\n"\n'
    elif op_type in ['sse.mov.uncond.mem_r', 'sse.mov.cond.mem_r', 'avx.mov.uncond.mem_r', 'avx.mov.cond.mem_r']:
      return '"movsd <W_XMMREG>, QWORD PTR[<MEMADDR>]\\n"\n'
    elif op_type in ['sse.mov.uncond.mem_w', 'sse.mov.cond.mem_w', 'avx.mov.uncond.mem_w', 'avx.mov.cond.mem_w']:
      return '"movsd QWORD PTR[<MEMADDR>], <R_XMMREG>\\n"\n'
    elif op_type in ['sse.mov.uncond.no_mem', 'sse.mov.cond.no_mem', 'avx.mov.uncond.no_mem', 'avx.mov.cond.no_mem']:
      return '"movsd <W_XMMREG>, <R_XMMREG>\\n"\n'

    # ================================================================
    # Function call and return instruction
    # ================================================================
    elif 'base.func.call' in op_type:
      return f'"call dummy_call_func_{function_id}_block_{block_id}_rep_{replica_id}\\n"\n'
    elif 'base.func.ret' in op_type:
      return ''

    # ================================================================
    # Other special instructions
    # ================================================================
    if op_type == 'sse.crc32.no_mem':
      return '"crc32 <W_REG>, <R_REG>\\n"\n'

    # ================================================================
    # Other instructions
    # ================================================================
    elif op_type in ['base.other.mem_r', 'avx.other.mem_r', 'sse.other.mem_r']:
      op = random.choice(BASE_MUL_INT_OPS)
      return f'"{op} QWORD PTR[<MEMADDR>]\\n"\n'
    elif op_type in ['base.other.mem_w', 'base.other.mem_x', 'avx.other.mem_w', 'avx.other.mem_x', 'sse.other.mem_w', 'sse.other.mem_x']:
      op = random.choice(BASE_MUL_INT_OPS)
      return f'"{op} QWORD PTR[<MEMADDR>]\\n"\n'
    elif op_type in ['base.other.no_mem', 'avx.other.no_mem', 'sse.other.no_mem']:
      op = random.choice(BASE_MUL_INT_OPS)
      return f'"{op} <R_REG>\\n"\n'
    else:
      raise Exception('Invalid op_type: ' + op_type)

  def __shuffle_uncond_blocks(self, asm, function_id, block_id, replica_id):
    # Split blocks
    blocks = []
    curr_block = []
    for line in asm.splitlines():
      if re.match(r'^"jmp br_uncond_\w+\\n"$', line):
        curr_block.append(line)
        asm_block = '\n'.join(curr_block)
        blocks.append(asm_block)
        curr_block = []
      else:
        curr_block.append(line)
    # Last block
    asm_block = '\n'.join(curr_block)
    blocks.append(asm_block)
    # Shuffle blocks
    random.shuffle(blocks)
    # Merge blocks
    asm = '\n'.join(blocks) + '\n'
    asm = f'"jmp func_{function_id}_block_{block_id}_rep_{replica_id}_asm_start\\n"\n' + asm
    asm = asm + f'"func_{function_id}_block_{block_id}_rep_{replica_id}_asm_end:"\n'
    return asm

  def __allocate_regs(self, asm_lines):
    gp_regs = [r for r in GP_REG_NAMES if r not in CLOG_REGS]
    xmm_regs = [r for r in XMM_REGS]
    st_regs = [r for r in ST_REGS]
    reg_groups = {
        '<R_REG>': gp_regs,
        '<W_REG>': gp_regs,
        '<X_REG>': gp_regs,
        '<R_XMMREG>': xmm_regs,
        '<W_XMMREG>': xmm_regs,
        '<X_XMMREG>': xmm_regs,
        '<R_STREG>': st_regs,
        '<W_STREG>': st_regs,
        '<X_STREG>': st_regs,
    }
    inst_last_rd = {k: -1 for k in gp_regs + xmm_regs + st_regs}
    inst_last_wr = {k: -1 for k in gp_regs + xmm_regs + st_regs}
    for i in range(len(asm_lines)):
      asm = asm_lines[i]
      while ('<R_REG>' in asm or '<W_REG>' in asm or '<X_REG>' in asm or
              '<R_XMMREG>' in asm or '<W_XMMREG>' in asm or '<X_XMMREG>' in asm or
              '<R_STREG>' in asm or '<W_STREG>' in asm or '<X_STREG>' in asm):
        raw_distance = random.choices(
            population=list(self.data_dependency_distribution['raw'].keys()),
            weights=list(self.data_dependency_distribution['raw'].values()),
            k=1)[0]
        war_distance = random.choices(
            population=list(self.data_dependency_distribution['war'].keys()),
            weights=list(self.data_dependency_distribution['war'].values()),
            k=1)[0]
        waw_distance = random.choices(
            population=list(self.data_dependency_distribution['waw'].keys()),
            weights=list(self.data_dependency_distribution['waw'].values()),
            k=1)[0]
        reg_label = re.findall(r'<[A-Z_]+REG>', asm)[0]
        if reg_label.startswith('<R_'):
          reg_name = min(reg_groups[reg_label], key=lambda k: abs(
              i - inst_last_wr[k] - raw_distance))
          asm = reg(reg_name, 64).join(asm.rsplit(reg_label, 1))
          inst_last_rd[reg_name] = i
        elif reg_label.startswith('<W_'):
          # Weight of WAW and WAR is equal
          reg_name = min(reg_groups[reg_label],
                         key=lambda k: 0.5 *
                         abs(i - inst_last_rd[k] - war_distance)
                         + 0.5 * abs(i - inst_last_wr[k] - waw_distance))
          asm = reg(reg_name, 64).join(asm.rsplit(reg_label, 1))
          inst_last_wr[reg_name] = i
        elif reg_label.startswith('<X_'):
          # Larger weights on RAW dependency
          # TODO: Check if the magic number makes sense
          reg_name = min(reg_groups[reg_label],
                         key=lambda k: 0.8 *
                         abs(i - inst_last_wr[k] - raw_distance)
                         + 0.1 * abs(i - inst_last_rd[k] - war_distance)
                         + 0.1 * abs(i - inst_last_wr[k] - waw_distance))
          asm = reg(reg_name, 64).join(asm.rsplit(reg_label, 1))
          inst_last_rd[reg_name] = i
          inst_last_wr[reg_name] = i
        else:
          raise Exception('Invalid asm: ' + asm)
        asm_lines[i] = asm
    return asm_lines

  def __allocate_mem_addrs(self, asm_lines, mem_size, num_mem_accesses):
    num_cachelines_in_loop = min(num_mem_accesses, int(mem_size / CACHELINE_SIZE))
    n_repeat = max(1, int(num_mem_accesses / mem_size * CACHELINE_SIZE) + 1)
    rand_cacheline_indices = []
    if mem_size >= 512 * 1024:
      # TODO: change page shift size for tlb miss
      indices = list(range(num_cachelines_in_loop * self.page_multiplier))
    else:
      indices = list(range(num_cachelines_in_loop))
    random.shuffle(indices)
    for i in range(n_repeat):
      rand_cacheline_indices += indices
    idx = 0
    for i in range(len(asm_lines)):
      asm = asm_lines[i]
      while '<MEMADDR>' in asm:
        mem_addr = rand_cacheline_indices[idx] * CACHELINE_SIZE & (mem_size - 1)
        idx += 1
        asm = f'{reg(ADDR_OFFSET_REG, 64)} + {mem_addr}'.join(asm.rsplit('<MEMADDR>', 1))
      asm_lines[i] = asm
    return asm_lines

  def generate_asm_block(self, function_id, block_id, replica_id, mem_size, 
      num_static_insts, num_block_replicas, reqid_lower_bound, reqid_upper_bound):
    num_dynamic_insts = int(num_static_insts * max(1, np.round(self.num_dynamic_insts / num_static_insts)))
    mem_id = list(self.dcache_stats.keys()).index(mem_size)
    # Generate a random instruction
    asm = ''
    i = 0
    while i < num_static_insts:
      op_type = random.choices(
          population=list(self.imix_hist.keys()),
          weights=list(self.imix_hist.values()), k=1)[0]      
      asm += self.__asm_inst_generator(op_type, function_id, block_id, replica_id)
      if op_type in ['base.branch.cond.no_mem', 'base.branch.cond.mem_r']:
        i += 2
      else:
        i += 1

    asm = f'"func_{function_id}_block_{block_id}_rep_{replica_id}_asm_start:"\n' + asm
    asm = asm + f'"jmp func_{function_id}_block_{block_id}_rep_{replica_id}_asm_end\\n"\n'
    asm = self.__shuffle_uncond_blocks(asm, function_id, block_id, replica_id)
    asm_lines = asm.split('\n')
    asm_lines = self.__allocate_regs(asm_lines)
    num_static_mem_accesses = 0
    for asm in asm_lines:
      num_static_mem_accesses += asm.count('<MEMADDR>')
    if num_static_mem_accesses < 1:
      return ''
    asm_lines = self.__allocate_mem_addrs(
        asm_lines, mem_size, num_static_mem_accesses)

    # TODO: change page shift size for tlb miss
    if mem_size >= 512 * 1024:
      shift_size = min(
          num_static_mem_accesses * self.page_multiplier , int(mem_size / CACHELINE_SIZE)
      ) * CACHELINE_SIZE
    else:
      shift_size = min(
          num_static_mem_accesses, int(mem_size / CACHELINE_SIZE)
      ) * CACHELINE_SIZE
    
    block_asm_prefix = (
      # TODO: INIT XMM1 and st(0) TO BE A NON-ZERO VALUE
        f'if ((req_id & {self.num_reqs_per_iteration - 1}) >= {reqid_lower_bound} '
        f'&& (req_id & {self.num_reqs_per_iteration - 1}) < {reqid_upper_bound} '
        f'&& (req_id % {num_block_replicas}) == {replica_id}) {{\n'

        '__asm__ __volatile__ (\n'
        f'"mov {reg(LOOP_IDX_REG, 64)}, %5\\n"\n'
        f'"mov {reg(ADDR_OFFSET_REG, 64)}, %3\\n"\n'
        f'"mov {reg(POINTER_CHASE_REG, 64)}, %4\\n"\n'
        f':"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)\n'
        f':"r" (mem_data), "r" (curr_mem_addrs[{mem_id}]), "r" (curr_pointer_chasing_mem_addrs[{mem_id}]), "r" (req_id)\n'
        f':"cc", "{reg(BASE_ADDR_REG, 64)}", "{reg(TOP_ADDR_REG, 64)}", "{reg(ADDR_OFFSET_REG, 64)}", "{reg(LOOP_IDX_REG, 64)}", "{reg(RAND_REG, 64)}"\n'
        ');\n'

        '__asm__ __volatile__ (\n'
        # Initialize the random number
        f'"rdtsc\\n"\n'
        f'"mov {reg(RAND_REG, 64)}, rax\\n"\n'
        ');\n'
        
        '__asm__ __volatile__ (\n'
        f'"func_{function_id}_block_{block_id}_rep_{replica_id}_loop_start:"\n'
        f'"lea {reg(BASE_ADDR_REG, 64)}, QWORD PTR[%2]\\n"\n'
        f'"lea {reg(TOP_ADDR_REG, 64)}, QWORD PTR[%2 + {max(0, mem_size - shift_size)}]\\n"\n'
        f'"add {reg(LOOP_IDX_REG, 64)}, 1\\n"\n'

        # Random number generator
        f'"mov rax, {RAND_A}\\n"\n'
        f'"mul {reg(RAND_REG, 64)}\\n"\n'
        f'"mov {reg(RAND_REG, 64)}, rax\\n"\n'
        f'"add {reg(RAND_REG, 64)}, {RAND_C}\\n"\n'

        f'"cmp {reg(ADDR_OFFSET_REG, 64)}, {reg(TOP_ADDR_REG, 64)}\\n"\n'
        f'"jle bypass_reset_func_{function_id}_block_{block_id}_rep_{replica_id}\\n"\n'
        f'"mov {reg(ADDR_OFFSET_REG, 64)}, {reg(BASE_ADDR_REG, 64)}\\n"\n'
        f'"bypass_reset_func_{function_id}_block_{block_id}_rep_{replica_id}:"\n'
        f':"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)\n'
        f':"r" (mem_data), "r" (curr_mem_addrs[{mem_id}]), "r" (curr_pointer_chasing_mem_addrs[{mem_id}]), "r" (req_id)\n'
        f':"cc", "{reg(BASE_ADDR_REG, 64)}", "{reg(TOP_ADDR_REG, 64)}", "{reg(ADDR_OFFSET_REG, 64)}", "{reg(LOOP_IDX_REG, 64)}", "{reg(RAND_REG, 64)}"\n'
        ');\n'
    )

    block_asm_suffix = (
        '__asm__ __volatile__ (\n'
        f'"add {reg(ADDR_OFFSET_REG, 64)}, {shift_size}\\n"\n'
        f'"mov rdi, %5\\n"\n'
        f'"add rdi, {int(num_dynamic_insts / num_static_insts)}\\n"\n'
        f'"cmp {reg(LOOP_IDX_REG, 64)}, rdi\\n"\n'
        f'"jl func_{function_id}_block_{block_id}_rep_{replica_id}_loop_start\\n"\n'
        f'"mov %0, {reg(ADDR_OFFSET_REG, 64)}\\n"\n'
        f'"mov %1, {reg(POINTER_CHASE_REG, 64)}\\n"\n'
        f'"jmp end_func_{function_id}_block_{block_id}_rep_{replica_id}\\n"\n'
        f'"dummy_call_func_{function_id}_block_{block_id}_rep_{replica_id}:"\n'
        f'"ret\\n"\n'
        f'"end_func_{function_id}_block_{block_id}_rep_{replica_id}:"\n'
        f':"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)\n'
        f':"r" (mem_data), "r" (curr_mem_addrs[{mem_id}]), "r" (curr_pointer_chasing_mem_addrs[{mem_id}]), "r" (req_id)\n'
        f':"cc", "{reg(BASE_ADDR_REG, 64)}", "{reg(TOP_ADDR_REG, 64)}", "{reg(ADDR_OFFSET_REG, 64)}", "{reg(LOOP_IDX_REG, 64)}", "{reg(RAND_REG, 64)}"\n'
        ');\n'
        f'curr_mem_addrs[{mem_id}] = next_mem_addr;\n'
        f'curr_pointer_chasing_mem_addrs[{mem_id}] = next_pointer_chasing_mem_addr;\n'
        '}\n'
    )
    
    if not self.debug:
      asm_lines = ['__asm__ __volatile__ ('] + asm_lines
      asm_lines = asm_lines + [');']
      return block_asm_prefix + '\n'.join(asm_lines) + block_asm_suffix
    else:
      debug_asm_lines = []
      for asm in asm_lines:
        if asm != '':
          debug_asm_lines.append(f'__asm__ __volatile__ ({asm});')
      return block_asm_prefix + '\n'.join(debug_asm_lines) + block_asm_suffix

  def generate_asm(self):
    self.dcache_req_range = {}
    idx = 0
    for s in self.dcache_stats.keys():
      idx_next = int(
          np.round(idx + self.dcache_stats[s] * self.num_reqs_per_iteration))
      if list(self.dcache_stats.keys())[-1] == s:
        self.dcache_req_range[self.num_reqs_per_iteration] = s
        break
      if idx_next >= self.num_reqs_per_iteration:
        idx_next = self.num_reqs_per_iteration
        self.dcache_req_range[idx_next] = s
        break
      elif idx_next not in self.dcache_req_range:
        self.dcache_req_range[idx_next] = s
      idx = idx_next
    self.icache_req_range = {}
    idx = 0
    for s in list(self.icache_stats.keys())[::-1]:
      idx_next = int(
          np.round(idx + self.icache_stats[s] * self.num_reqs_per_iteration))
      if list(self.icache_stats.keys())[0] == s:
        self.icache_req_range[self.num_reqs_per_iteration] = s
        break
      if idx_next >= self.num_reqs_per_iteration:
        idx_next = self.num_reqs_per_iteration
        self.icache_req_range[idx_next] = s
        break
      elif idx_next not in self.dcache_req_range:
        self.icache_req_range[idx_next] = s
      idx = idx_next

    self.dcache_icache_req_range = {}
    idx = 0
    i = 0
    j = 0
    while idx < self.num_reqs_per_iteration:
      dcache_key = list(self.dcache_req_range.keys())[i]
      icache_key = list(self.icache_req_range.keys())[j]
      if dcache_key < icache_key:
        self.dcache_icache_req_range[dcache_key] = (self.dcache_req_range[dcache_key], self.icache_req_range[icache_key])
        idx = dcache_key
        i = i + 1
      else:
        self.dcache_icache_req_range[icache_key] = (self.dcache_req_range[dcache_key], self.icache_req_range[icache_key])
        idx = icache_key
        j = j + 1

    asm = (
    '#include <cstdint>\n'
    'using namespace std;\n'
    )

    # Set the number of replicas of each block as one if not specified.
    for _, (dcache_size, icache_size) in self.dcache_icache_req_range.items():
      if icache_size not in self.num_block_replicas:
        self.num_block_replicas[icache_size] = 1

    asm_futures = {}
    with concurrent.futures.ProcessPoolExecutor(max_workers=88) as executer:
      for function_id in range(self.num_asm_functions):
        asm_futures[function_id] = {}
        self.br_cond_label_idx[function_id] = {}
        self.br_uncond_label_idx[function_id] = {}
        block_id = 0
        reqid_lower_bound = 0
        for reqid_upper_bound, (dcache_size, icache_size) in self.dcache_icache_req_range.items():
          asm_futures[function_id][block_id]={}
          self.br_cond_label_idx[function_id][block_id] = {}
          self.br_uncond_label_idx[function_id][block_id] = {}
          num_static_insts = int(icache_size / self.mean_inst_size)
          num_block_replicas = self.num_block_replicas[icache_size]
          icache_replicas = len([v for v in self.dcache_icache_req_range.values() if v[1] == icache_size])
          if num_static_insts >  self.num_dynamic_insts:
            final_num_block_replicas = int(num_static_insts / self.num_dynamic_insts * self.num_block_replicas[icache_size] / icache_replicas)
            num_static_insts = self.num_dynamic_insts
          else:
            final_num_block_replicas = int(num_block_replicas / icache_replicas)
          final_num_block_replicas = max(1, final_num_block_replicas)

          for replica_id in range(final_num_block_replicas):
            self.br_cond_label_idx[function_id][block_id][replica_id] = 0
            self.br_uncond_label_idx[function_id][block_id][replica_id] = 0
            asm_futures[function_id][block_id][replica_id] = executer.submit(
              self.generate_asm_block,
              function_id, block_id, replica_id, dcache_size, num_static_insts, final_num_block_replicas, reqid_lower_bound, reqid_upper_bound
            )
            
          self.base_mem_addr += dcache_size
          block_id += 1
          reqid_lower_bound = reqid_upper_bound

    for function_id in asm_futures:
      if function_id == 0:
        asm += (
          f'void runAssembly(uint64_t* mem_data, uint64_t req_id, uint64_t* curr_mem_addrs, uint64_t* curr_pointer_chasing_mem_addrs) {{\n'
          f'uint64_t next_mem_addr;\n'
          f'uint64_t next_pointer_chasing_mem_addr;\n'
      )
      else:
        asm += (
          f'void runAssembly{function_id}(uint64_t* mem_data, uint64_t req_id, uint64_t* curr_mem_addrs, uint64_t* curr_pointer_chasing_mem_addrs) {{\n'
          f'uint64_t next_mem_addr;\n'
          f'uint64_t next_pointer_chasing_mem_addr;\n'
      )

      if function_id == 0:
        asm += (
            # TODO: Temp REP MOVSB
            '__asm__ __volatile__ (\n'
            f'"lea rdi, QWORD PTR[%0]\\n"\n'
            f'"lea rsi, QWORD PTR[%0+{self.num_reps * 8}]\\n"\n'
            f'"mov rcx, {self.num_reps}\\n"\n'
            f'"rep movsb byte ptr [rdi], byte ptr [rsi]\\n"\n'
            f':\n'
            f':"r" (mem_data)\n'
            f':"cc", "rdi", "rsi", "rcx"\n'
            ');\n'
        )
      for block_id in asm_futures[function_id]:
        for replica_id in asm_futures[function_id][block_id]:
          asm += asm_futures[function_id][block_id][replica_id].result()
          asm += '\n'
      asm += '}\n'
    return asm