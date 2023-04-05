from base_analyzer import BaseAnalyzer
import re

GP_REG_NAMES = [
    'a', 'b', 'c', 'd', 'sp', 'bp', 'si', 'di', 'r8', 'r9', 'r10', 'r11', 'r12', 'r13', 'r14', 'r15']

GP_REGS = [
    'al', 'bl', 'cl', 'dl', 'ah', 'bh', 'ch', 'dh', 'spl', 'bpl', 'sil', 'dil', # r8
    'r8b', 'r9b', 'r10b', 'r11b', 'r12b', 'r13b', 'r14b', 'r15b',               # r8
    "ax", "cx", "dx", "bx", "sp", "bp", "si", "di",                             # r16
    "r8w", "r9w", "r10w", "r11w", "r12w", "r13w", "r14w", "r15w",               # r16
    "eax", "ecx", "edx", "ebx", "esp", "ebp", "esi", "edi",                     # r32
    "r8d", "r9d", "r10d", "r11d", "r12d", "r13d", "r14d", "r15d",               # r32
    "rax", "rcx", "rdx", "rbx", "rsp", "rbp", "rsi", "rdi",                     # r64
    "r8", "r9", "r10", "r11", "r12", "r13", "r14", "r15"                        # r64
]

MAX_INT = 2**32

def get_reg_name(reg):
  for kernel in GP_REG_NAMES:
    if kernel in reg:
      if kernel == 'b' and reg in ['r8b', 'r9b', 'r10b', 'r11b', 'r12b', 'r13b', 'r14b', 'r15b']:
        continue
      if kernel == 'd' and reg in ['r8d', 'r9d', 'r10d', 'r11d', 'r12d', 'r13d', 'r14d', 'r15d']:
        continue
      return kernel
  return reg

def reg_equal(reg1, reg2):
  if reg1 not in GP_REGS or reg2 not in GP_REGS:
    return reg1 == reg2
  else:
    kernel1 = get_reg_name(reg1)
    kernel2 = get_reg_name(reg2)
    return kernel1 == kernel2

def merge_distribution(dist0, dist1):
  ret = {}
  for k in set(dist0.keys()).union(set(dist1.keys())):
    if k in dist0 and k in dist1:
      ret[k] = dist0[k] + dist1[k]
    elif k in dist0:
      ret[k] = dist0[k]
    else:
      ret[k] = dist1[k]
  return ret

def bin_distribution(dist, bins):
  def closest(bins, K):
    return bins[min(range(len(bins)), key=lambda i: abs(bins[i] - K))]

  ret = {k: 0 for k in bins}
  for k, v in dist.items():
    binned_k = closest(bins, k)
    ret[binned_k] += v

  total_count = sum(ret.values())
  for k in ret.keys():
    ret[k] /= total_count
  return ret

class DataDependencyAnalyzer(BaseAnalyzer):

  def __init__(self, max_bb_depth=256, bins=[1, 2, 4, 8, 16, 32, 64, 128, 256, 512, 1024], *args, **kwargs):
    super().__init__(parse_dcfg=True, parse_asmdb=True, *args, **kwargs)
    self.max_bb_depth = max_bb_depth
    self.bins = bins

    self.__parse_basic_block_regs()

    self.__basic_block_reg_dep_distances()

  def __parse_inst_operand(self, inst):
    """ Find out the type and rd/wr of the operand.
    Args:
      inst: The x86 assembly instruction.
    Returns:
      A distionary of operands
      {
        'rd_regs': [rd_regs],
        'wr_regs': [wr_regs],
        'rd_mems': [rd_mems],
        'wr_mems': [wr_mems]
      }
    """
    if 'nop' in inst:
      return {
          'rd_regs': [],
          'wr_regs': [],
          'rd_mems': [],
          'wr_mems': []
      }

    # Ignore some prefixes
    inst = inst.replace('rep ', '')
    inst = inst.replace('repz ', '')
    inst = inst.replace('repnz ', '')
    inst = inst.replace('repe ', '')
    inst = inst.replace('repne ', '')
    inst = inst.replace('bnd ', '')
    inst = inst.replace('lock ', '')

    op = inst.split()[0]
    operands = inst.replace(f'{op} ', '').replace(f'{op}', '').split(', ')
    operand_addrs = tuple()
    operand_types = tuple()
    mem_addr_regs = list()
    for operand in operands:
      if operand:
        if operand in self.x86regs:
          operand_types += ('reg',)
          operand_addrs += (operand, )
        elif re.match(r'[byte|word|dword|qword|xmmword ]*ptr [a-z:]*\[[a-zA-Z0-9\+\-\*\:]+\]', operand):
          try:
            operand_types += ('mem',)
            addr = re.findall(r'\[[a-z0-9\+\-\*\:]+\]', operand)[0][1:-1]
            operand_addrs += (addr, )
            re_results = re.findall(r'[a-z0-9]+', operand)
            for reg in re_results:
              if reg in GP_REGS:
                mem_addr_regs.append(get_reg_name(reg))
          except:
            print(operand)
            raise
        elif re.match(r'0x[0-9a-f]+', operand):
          operand_types += ('imm',)
          operand_addrs += (None, )
        elif operand == 'st':
          pass
        else:
          print(inst, operand)
          raise ValueError('Unsupported operand type')

    # Special case for instructions with implicit register usages
    if inst.startswith('mul '):
      try:
        assert len(operands) == 1
      except:
        print(inst, operands)
        raise
      operand_types = ('reg', 'reg', operand_types[0])
      operand_addrs = ('rdx', 'rax', operand_addrs[0])
      operand_rwx = ('w', 'x', 'r')
    elif inst.startswith('imul ') and len(operands) == 1:
      operand_types = ('reg', 'reg', operand_types[0])
      operand_addrs = ('rdx', 'rax', operand_addrs[0])
      operand_rwx = ('w', 'x', 'r')
    elif inst.startswith('div ') or inst.startswith('idiv '):
      assert len(operands) == 1
      operand_types = ('reg', 'reg', operand_types[0])
      operand_addrs = ('rdx', 'rax', operand_addrs[0])
      operand_rwx = ('x', 'x', 'r')
    elif inst.startswith('cmpxchg '):
      assert len(operands) == 2
      operand_types = (operand_types[0], operand_types[1], 'reg')
      operand_addrs = (operand_addrs[0], operand_addrs[1], 'rax')
      operand_rwx = ('x', 'r', 'r')
    else:
      try:
        operand_rwx = self.x86operands[op][operand_types]
      except:
        operand_types = tuple()

    result = {
        'rd_regs': mem_addr_regs,
        'wr_regs': [],
        'rd_mems': [],
        'wr_mems': []
    }
    for i in range(len(operand_types)):
      if operand_types[i] == 'reg':
        if operand_rwx[i] == 'r':
          result['rd_regs'] += [get_reg_name(operand_addrs[i])]
        elif operand_rwx[i] == 'w':
          result['wr_regs'] += [get_reg_name(operand_addrs[i])]
        elif operand_rwx[i] == 'x':
          result['rd_regs'] += [get_reg_name(operand_addrs[i])]
          result['wr_regs'] += [get_reg_name(operand_addrs[i])]
        else:
          raise ValueError('Unsupported operand type')
      elif operand_types[i] == 'mem':
        if operand_rwx[i] == 'r':
          result['rd_mems'] += [operand_addrs[i]]
        elif operand_rwx[i] == 'w':
          result['wr_mems'] += [operand_addrs[i]]
        elif operand_rwx[i] == 'x':
          result['rd_mems'] += [operand_addrs[i]]
          result['wr_mems'] += [operand_addrs[i]]
        else:
          raise ValueError('Unsupported operand type')
      elif operand_types[i] == 'imm':
        pass
      else:
        raise ValueError('Unsupported operand type')

    return result

  def __parse_basic_block_regs(self):
    """Find out registers in each instruction in each basic block."""

    self.basic_block_inst_regs = {}
    self.basic_block_regs = {}
    self.basic_block_reg_insts = {}
    
    for bb_id in self.app_dcfg.nodes:
      inst_idx = 0
      self.basic_block_inst_regs[bb_id] = {}
      self.basic_block_regs[bb_id] = {
            'rd_regs': set(), 'wr_regs': set()}
      self.basic_block_reg_insts[bb_id] = {}
      for inst in self.app_basic_blocks[bb_id]['insts']:
        self.basic_block_inst_regs[bb_id][inst_idx] = {
            'rd_regs': set(), 'wr_regs': set()}
        inst = inst['inst']
        operands = self.__parse_inst_operand(inst)
        for rd_reg in operands['rd_regs']:
          if rd_reg in GP_REG_NAMES:
            self.basic_block_inst_regs[bb_id][inst_idx]['rd_regs'].add(rd_reg)
            self.basic_block_regs[bb_id]['rd_regs'].add(rd_reg)
            if rd_reg not in self.basic_block_reg_insts[bb_id]:
              self.basic_block_reg_insts[bb_id][rd_reg] = {'rd': [], 'wr': []}
            self.basic_block_reg_insts[bb_id][rd_reg]['rd'].append(inst_idx)
        for wr_reg in operands['wr_regs']:
          if wr_reg in GP_REG_NAMES:
            self.basic_block_inst_regs[bb_id][inst_idx]['wr_regs'].add(wr_reg)
            self.basic_block_regs[bb_id]['wr_regs'].add(wr_reg)
            if wr_reg not in self.basic_block_reg_insts[bb_id]:
              self.basic_block_reg_insts[bb_id][wr_reg] = {'rd': [], 'wr': []}
            self.basic_block_reg_insts[bb_id][wr_reg]['wr'].append(inst_idx)
        inst_idx += 1

  def __basic_block_reg_dep_distances(self):

    def helper(bb_id, reg, rw, prob, dist, depth):
      distances = {}
      if depth > self.max_bb_depth:
        # TODO: Handle this case: self.bb_reg_distances[bb_id][reg][rw] = {-1: 1.0}
        return {MAX_INT: prob}
      if self.bb_reg_distances[bb_id][reg][rw]:
        result = {}
        for k, v in self.bb_reg_distances[bb_id][reg][rw].items():
          result[k + dist] = v * prob
        return result
      if reg in self.basic_block_regs[bb_id][f'{rw}_regs']:
        self.bb_reg_distances[bb_id][reg][rw] = {
            self.app_dcfg.nodes[bb_id]["insts"] - self.basic_block_reg_insts[bb_id][reg][rw][-1]: 1.0}
        assert len(self.basic_block_reg_insts[bb_id][reg][rw])
        return {self.app_dcfg.nodes[bb_id]["insts"] - self.basic_block_reg_insts[bb_id][reg][rw][-1] + dist: prob}

      for parent_bb_id in self.app_dcfg.predecessors(bb_id):
        curr_distances = helper(parent_bb_id, reg, rw, prob *
                                self.app_dcfg.edges[parent_bb_id,
                                                bb_id]['backward_prob'],
                                dist + self.app_dcfg.nodes[bb_id]["insts"],
                                depth + 1)
        distances = merge_distribution(distances, curr_distances)
      if not distances:
        return {MAX_INT: prob}
      for k, v in distances.items():
        if v > 0 and prob > 0:
          self.bb_reg_distances[bb_id][reg][rw][k - dist] = v / prob
      return distances

    self.bb_reg_distances = {
      bb_id: {k: {'rd': {}, 'wr': {}} for k in GP_REG_NAMES}
      for bb_id in self.app_dcfg.nodes
    }
    
    for bb_id in self.app_dcfg.nodes:
      for reg in GP_REG_NAMES:
        self.bb_reg_distances[bb_id][reg]['rd'] = helper(
            bb_id, reg, 'rd', 1.0, 0, 0)
        self.bb_reg_distances[bb_id][reg]['wr'] = helper(
            bb_id, reg, 'wr', 1.0, 0, 0)

  def run_analysis(self):

    raw_distribution = {}
    war_distribution = {}
    waw_distribution = {}

    for bb_id in self.app_dcfg.nodes:
      for inst_idx in range(self.app_dcfg.nodes[bb_id]['insts']):
        rd_regs = self.basic_block_inst_regs[bb_id][inst_idx]['rd_regs']
        wr_regs = self.basic_block_inst_regs[bb_id][inst_idx]['wr_regs']
        for rd_reg in rd_regs:
          # RAW dependency
          if not self.basic_block_reg_insts[bb_id][rd_reg]['wr'] or inst_idx <= self.basic_block_reg_insts[bb_id][rd_reg]['wr'][0]:
            tmp_distribution = {}
            for parent_bb_id in self.app_dcfg.predecessors(bb_id):
              for dist, prob in self.bb_reg_distances[parent_bb_id][rd_reg]['wr'].items():
                dist += inst_idx
                executions = self.app_dcfg.nodes[bb_id]["executions"] * \
                    self.app_dcfg.edges[parent_bb_id, bb_id]['backward_prob'] * prob
                if dist not in tmp_distribution:
                  tmp_distribution[dist] = 0
                tmp_distribution[dist] += executions
            raw_distribution = merge_distribution(
                raw_distribution, tmp_distribution)
          else:
            for i in range(len(self.basic_block_reg_insts[bb_id][rd_reg]['wr'])):
              if self.basic_block_reg_insts[bb_id][rd_reg]['wr'][i] >= inst_idx:
                break
            prev_inst_idx = self.basic_block_reg_insts[bb_id][rd_reg]['wr'][i - 1]
            if inst_idx - prev_inst_idx not in raw_distribution:
              raw_distribution[inst_idx - prev_inst_idx] = 0
            raw_distribution[inst_idx - prev_inst_idx] += self.app_dcfg.nodes[bb_id]["executions"]
        for wr_reg in wr_regs:
          # WAR dependency
          if not self.basic_block_reg_insts[bb_id][wr_reg]['rd'] or inst_idx <= self.basic_block_reg_insts[bb_id][wr_reg]['rd'][0]:
            tmp_distribution = {}
            for parent_bb_id in self.app_dcfg.predecessors(bb_id):
              for dist, prob in self.bb_reg_distances[parent_bb_id][wr_reg]['rd'].items():
                dist += inst_idx
                executions = self.app_dcfg.nodes[bb_id]["executions"] * \
                    self.app_dcfg.edges[parent_bb_id, bb_id]['backward_prob'] * prob
                if dist not in tmp_distribution:
                  tmp_distribution[dist] = 0
                tmp_distribution[dist] += executions
            war_distribution = merge_distribution(
                war_distribution, tmp_distribution)
          else:
            for i in range(len(self.basic_block_reg_insts[bb_id][wr_reg]['rd'])):
              if self.basic_block_reg_insts[bb_id][wr_reg]['rd'][i] >= inst_idx:
                break
            prev_inst_idx = self.basic_block_reg_insts[bb_id][wr_reg]['rd'][i - 1]
            if inst_idx - prev_inst_idx not in war_distribution:
              war_distribution[inst_idx - prev_inst_idx] = 0
            war_distribution[inst_idx - prev_inst_idx] += self.app_dcfg.nodes[bb_id]["executions"]

          # WAW dependency
          if not self.basic_block_reg_insts[bb_id][wr_reg]['wr'] or inst_idx <= self.basic_block_reg_insts[bb_id][wr_reg]['wr'][0]:
            tmp_distribution = {}
            for parent_bb_id in self.app_dcfg.predecessors(bb_id):
              for dist, prob in self.bb_reg_distances[parent_bb_id][wr_reg]['wr'].items():
                dist += inst_idx
                executions = self.app_dcfg.nodes[bb_id]["executions"] * \
                    self.app_dcfg.edges[parent_bb_id, bb_id]['backward_prob'] * prob
                if dist not in tmp_distribution:
                  tmp_distribution[dist] = 0
                tmp_distribution[dist] += executions
            waw_distribution = merge_distribution(
                waw_distribution, tmp_distribution)
          else:
            for i in range(len(self.basic_block_reg_insts[bb_id][wr_reg]['wr'])):
              if self.basic_block_reg_insts[bb_id][wr_reg]['wr'][i] >= inst_idx:
                break
            prev_inst_idx = self.basic_block_reg_insts[bb_id][wr_reg]['wr'][i - 1]
            if inst_idx - prev_inst_idx not in waw_distribution:
              waw_distribution[inst_idx - prev_inst_idx] = 0
            waw_distribution[inst_idx - prev_inst_idx] += self.app_dcfg.nodes[bb_id]["executions"]

    binned_raw_distribution = bin_distribution(raw_distribution, self.bins)
    binned_war_distribution = bin_distribution(war_distribution, self.bins)
    binned_waw_distribution = bin_distribution(waw_distribution, self.bins)
    return {'raw': binned_raw_distribution,
            'war': binned_war_distribution,
            'waw': binned_waw_distribution}
