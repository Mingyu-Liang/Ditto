from base_analyzer import BaseAnalyzer
import re
import os

IFORM_INST_PREFIXES = [
  'LOCK',
  'REP',
  'REPE',
  'REPZ',
  'REPNZ',
  'REPNE',
  'REX',
]

class InstMixAnalyzer(BaseAnalyzer):
  def __init__(self, *args, **kwargs):
    super().__init__(parse_asmdb=True, *args, **kwargs)

    app_imix_file = os.path.join(self.input_path, f'{self.app}', 'sde', 'sde-mix-out.txt')
    skeleton_imix_file = os.path.join(self.input_path, f'{self.skeleton}', 'sde', 'sde-mix-out.txt')
    
    self.app_imix_hist = self.__parse_imix_file(app_imix_file, tids=self.app_tids)
    self.skeleton_imix_hist = self.__parse_imix_file(skeleton_imix_file, tids=self.skeleton_tids)

    self.x86inst_extensions = dict()
    for x86inst in self.x86insts:
      self.x86inst_extensions[x86inst['name']] = x86inst['extensions']

  def __parse_imix_file(self, imix_file, tids):
    imix_hist = {}

    with open(imix_file, 'r') as f:
      imix_file_lines = f.readlines()
    
    state = 'idle'
    curr_tid = -1

    tid_line_pattern = re.compile(r'^# TID (\d+)$')
    imix_line_imix_pattern = re.compile(r'^(\*?[a-zA-Z0-9-_]+)')
    imix_line_count_pattern = re.compile(r'^\S*\s*(\d+)$')

    for line in imix_file_lines:
      if state == 'idle':
        if '$dynamic-counts' in line:
          state = 'get_tid'
      elif state == 'get_tid':
        if '# TID ' in line:
          curr_tid = int(tid_line_pattern.findall(line)[0])
          if tids and curr_tid not in tids:
            state = 'omit'
          else:
            state = 'parse'
      elif state == 'parse':
        if imix_line_imix_pattern.match(line):
          imix = imix_line_imix_pattern.findall(line)[0]
          count = int(imix_line_count_pattern.findall(line)[0])
          if imix not in imix_hist:
            imix_hist[imix] = 0
          imix_hist[imix] += count
        elif '# END_DYNAMIC_STATS' in line:
          state = 'idle'
      elif state == 'omit':
        if '# END_DYNAMIC_STATS' in line:
          state = 'idle'

    return imix_hist

  def __catagorize_imix(self, imix_str):
    op = ''
    if not imix_str.startswith('*'):
      keywords = imix_str.split('_')
      # Look for prefixes
      for w in keywords:
        if w in IFORM_INST_PREFIXES:
          keywords.remove(w)
          break
      # Look for op
      op = keywords.pop(0).lower()
      
      # Sppecial cases for MOVSD_XMM_MEMsd_XMMsd
      if op == 'movsd':
        keywords.pop(0)

      # Look for operands
      inst_operands = tuple()
      
      # Special case for instructions with implicit operand usages at beginning
      if op in ['mul', 'imul', 'div', 'idiv']:
        if len(keywords) == 1:
          inst_operands += ('reg', 'reg')

      for w in keywords:
        if 'GPR' in w or 'XMM' in w or 'YMM' in w  or 'OrAX' in w or 'AL' in w or 'CL' in w:
          inst_operands += ('reg', )
        elif 'MEM' in w or 'AGEN' in w:
          inst_operands += ('mem', )
        elif 'IMM' in w or 'ONE' in w:
          inst_operands += ('imm', )
        else:
          # TODO: Handle other operand types
          pass

      # Special case for instructions with implicit operand usages at end
      if op in ['cmpxchg', 'pcmpistri', 'vpcmpistri']:
        inst_operands += ('reg', )
      if op in ['xrstor', 'xsavec']:
        inst_operands += ('reg', 'reg')

      mem_rwx = 'no_mem'
      for i in range(len(inst_operands)):
        if inst_operands not in self.x86operands[op]:
          # TODO: Handle other operand types
          # pass
          print(op, imix_str, inst_operands, self.x86operands[op])
        if inst_operands[i] == 'mem':
          mem_operand_idx = inst_operands.index('mem')
          if self.x86operands[op][inst_operands][mem_operand_idx] == 'r':
            mem_rwx = 'mem_r'
          elif self.x86operands[op][inst_operands][mem_operand_idx] == 'w':
            mem_rwx = 'mem_w'
          elif self.x86operands[op][inst_operands][mem_operand_idx] == 'x':
            mem_rwx = 'mem_x'
          else:
            print(op, inst_operands, self.x86operands[op][inst_operands])
            raise Exception('Unknown memory operand type')

      op_type = 'base'

      for ext in self.x86inst_extensions[op].keys():
        if 'sse' in ext.lower():
          op_type = 'sse'
          break
        elif 'avx' in ext.lower():
          op_type = 'avx'
          break
      
      if op in ['mov', 'movsx', 'movzx', 'push', 'pop', 'movaps', 
          'movdqu', 'movsxd', 'movups', 'movsq', 'stosq', 'vmovdqa', 'vmovdqu',]:
        op_catagory = 'mov.uncond'
      elif op.startswith('cmov') or op.startswith('set'):
        op_catagory = 'mov.cond'
      elif op in [
        'ja', 'jae', 'jb', 'jbe', 'jc', 'je', 'jg', 'jge', 'jl', 'jle', 'jna', 
        'jnae', 'jnb', 'jnbe', 'jnc', 'jne', 'jng', 'jnge', 'jnl', 'jnle', 'jno', 
        'jnp', 'jns', 'jnz', 'jo', 'jp', 'jpe', 'jpo', 'js', 'jz'
      ]:
        op_catagory = 'branch.cond'
      elif op in ['jmp']:
        op_catagory = 'branch.uncond'
      elif op in ['add', 'adc', 'xadd', 'inc', 'dec', 'cmp', 'neg', 'sub', 'and', 'andn',
          'or', 'shl', 'shr', 'sal', 'sar', 'xor', 'pxor', 'not', 'rcl', 'rcr', 'rol', 'ror',
          'abs', 'test', 'sbb', 'lea', 'nop']:
        op_catagory = 'arith.int'
      elif op in ['mul', 'imul']:
        op_catagory = 'mul.int'
      elif op in ['div', 'idiv']:
        op_catagory = 'div.int'
      elif op in ['fadd', 'fsub', 'fucom', 'fisub', 'fiadd', 'addpd', 'addsd', 
          'addps', 'addss', 'subpd', 'subsd', 'subps', 'subss',
          'addsubpd', 'addsubps']:
        op_catagory = 'arith.fp'
      elif op in ['fmul', 'fmulp', 'fimul', 'mulpd', 'mulsd', 'mulps', 'mulss']:
        op_catagory = 'mul.fp'
      elif op in ['fdiv', 'fdivp', 'fidiv', 'divpd', 'divsd', 'divps', 'divss']:
        op_catagory = 'div.fp'
      elif op in ['crc32']:
        op_catagory = 'crc32'
      else:
        op_catagory = 'other'
      # Special consideration for call, ret, push, and pop:
      if op == 'call':
        return 'base.func.call.mem_w'
      elif op == 'ret':
        return 'base.func.ret.mem_r'
      elif op == 'push':
        return 'base.mov.uncond.mem_w'
      elif op == 'pop':
        return 'base.mov.uncond.mem_r'

      # Special consideration for rep string instructions
      if op in ['movsb', 'movsq']:
        return 'base.rep.movs'
      elif op in ['lodsb', 'lodsq']:
        return 'base.rep.lods'
      elif op in ['stosb', 'stosq']:
        return 'base.rep.stos'
      
      return f'{op_type}.{op_catagory}.{mem_rwx}'
    else:
      return None

  def __catagorize_ldst(self, imix):
    if imix == '*mem-read':
      return 'load'
    elif imix == '*mem-write':
      return 'store'
    else:
      return None
  
  def run_analysis(self):
    hist = {}
    ldst_hist = {}
    for app_imix in self.app_imix_hist:
      catagory = self.__catagorize_imix(app_imix)
      if catagory is not None:
        if catagory not in hist:
          hist[catagory] = 0
        hist[catagory] += self.app_imix_hist[app_imix]

    for skeleton_imix in self.skeleton_imix_hist:
      catagory = self.__catagorize_imix(skeleton_imix)
      if catagory is not None and catagory in hist:
        hist[catagory] = max(0, hist[catagory] - self.skeleton_imix_hist[skeleton_imix])

    for app_ldst in self.app_imix_hist:
      ldst = self.__catagorize_ldst(app_ldst)
      if ldst is not None:
        if ldst not in ldst_hist:
          ldst_hist[ldst] = 0
        ldst_hist[ldst] += self.app_imix_hist[app_ldst]
    
    for skeleton_ldst in self.skeleton_imix_hist:
      ldst = self.__catagorize_ldst(skeleton_ldst)
      if ldst is not None:
        ldst_hist[ldst] = max(0, ldst_hist[ldst] - self.skeleton_imix_hist[skeleton_ldst])

    # Adjust base.arith.int.no_mem since every conditional branch has a test
    hist['base.arith.int.no_mem'] = max(0, hist['base.arith.int.no_mem'] - hist['base.branch.cond.no_mem'])
    # Do not consider rep instructions
    hist['base.rep.movs'] = 0
    hist['base.rep.lods'] = 0
    hist['base.rep.stos'] = 0

    # Normalize
    total = sum(hist.values())
    if total != 0:
      for catagory in hist:
        hist[catagory] /= total
    else:
      hist["base.arith.int.no_mem"] = 1.0
    total = sum(ldst_hist.values())
    if total != 0:
      for ldst in ldst_hist:
        ldst_hist[ldst] /= total
    else:
      ldst_hist["load"] = 1.0
    return hist, ldst_hist