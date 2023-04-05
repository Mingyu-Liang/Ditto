import abc
import json
import os
import re
import networkx as nx
import itertools

class BaseAnalyzer(abc.ABC):
  """
  Base class of analyzer
  """

  def __init__(self, app, skeleton, input_path, app_tids, skeleton_tids, parse_dcfg=False, 
      parse_asmdb=False, parse_itrace=False):
    """
    Initialize the analyzer
    """
    self.app = app
    self.skeleton = skeleton
    self.input_path = input_path
    self.app_tids = app_tids
    self.skeleton_tids = skeleton_tids

    if parse_dcfg:
      self.__dcfg('app')
      self.__dcfg('skeleton')

    if parse_asmdb:
      x86db_path = "./asmdb"
      # x86 instruction database
      with open(os.path.join(x86db_path, 'x86insts.json')) as f:
        self.x86insts = json.load(f)
      # x86 database
      with open(os.path.join(x86db_path, 'x86data.json')) as f:
        self.x86data = json.load(f)
      self.x86operands = self.__parse_x86operands()
      self.x86regs = self.__parse_x86regs()

    if parse_itrace:
      self.__itrace('app')
      self.__itrace('skeleton')

  def __dcfg(self, name):
    sde_path = os.path.join(self.input_path, f'{getattr(self, name)}', 'sde')
    with open(os.path.join(sde_path, 'dcfg-out.dcfg.json'), 'r') as f:
      dcfg_json = json.load(f)
    with open(os.path.join(sde_path, 'dcfg-out.bb.txt'), 'r') as f:
      bb_lines = f.readlines()

    setattr(self, f'{name}_full_dcfg', self.__parse_dcfg(dcfg_json, bb_lines))
    setattr(self, f'{name}_dcfg', self.__build_target_tid_dcfg(name))
    setattr(self, f'{name}_basic_blocks', self.__parse_basic_blocks(bb_lines))

  def __itrace(self, name):
    itraces = {}
    sde_path = os.path.join(self.input_path, f'{getattr(self, name)}', 'sde')
    tids = getattr(self, f'{name}_tids')
    for root, dirs, files in os.walk(sde_path):
      for file in files:
        if file.startswith('sde-itrace-out') and re.match(r'(?<=tid)([0-9]+)', file):
          # The itrace file name: tid 0 has not suffix as tid0.
          idx = int(re.findall(r'(?<=tid)([0-9]+)', file)[0])
          with open(os.path.join(root, file), 'r') as f:
            itraces[idx] = f.readlines()
        if file == ('sde-itrace-out.txt'):
          with open(os.path.join(root, file), 'r') as f:
            itraces[0] = f.readlines()
    itraces = {k: v for k, v in itraces.items() if k in tids}
    setattr(self, f'{name}_itraces', itraces)

  def __parse_dcfg(self, dcfg_json, bb_lines):
    # Parse DCFG
    dcfg = nx.DiGraph()

    edge_types = {}
    for type in dcfg_json['EDGE_TYPES'][1:]:
      edge_types[type[0]] = type[1]

    bb_funcs = {}

    for process in dcfg_json['PROCESSES'][1:]:
      if 'IMAGES' in process[1]:
        for image in process[1]['IMAGES'][1:]:
          if 'ROUTINES' in image[3]:
            for routine in image[3]['ROUTINES'][1:]:
              entry_node = routine[0]
              for node in routine[2][1:]:
                bb_funcs[node[0]] = entry_node

    bb_info = {}
    bb_id = 0
    # Get basic block information:
    for line in bb_lines:
      if line.startswith('BLOCK'):
        if bb_id != 0:
          bb_info[bb_id] = {
              'addr': addr,
              'tail_addr': tail_addr,
              'executions': int(executions),
              'size': int(size),
              'insts': int(insts),
              'func': bb_funcs[bb_id]
          }
        bb_id = int(re.findall(r'(?<=\bBLOCK:\s)[0-9]+', line)[0])
        addr = re.findall(r'(?<=\bPC:\s)[0-9a-z]+', line)[0]
        executions = int(re.findall(r'(?<=\bEXECUTIONS:\s)[0-9]+', line)[0])
        size = int(re.findall(r'(?<=#BYTES:\s)[0-9]+', line)[0])
        icount = int(re.findall(r'(?<=ICOUNT:\s)[0-9]+', line)[0])
        insts = icount / executions

      elif line.startswith('XDIS'):
        tail_addr = re.findall(r'(?<=\bXDIS\s)[0-9a-z]+', line)[0]
    # Last basic block
    bb_info[bb_id] = {
        'addr': addr,
        'tail_addr': tail_addr,
        'executions': int(executions),
        'size': int(size),
        'insts': int(insts),
        'func': bb_funcs[bb_id]
    }

    # DCFG nodes
    for image in dcfg_json['PROCESSES'][1][1]['IMAGES'][1:]:
      image_addr = int(image[1], 16)
      image_data = image[3]
      if 'BASIC_BLOCKS' not in image_data:
        continue
      for basic_block in image_data['BASIC_BLOCKS'][1:]:
        dcfg.add_node(
            basic_block[0],
            addr=bb_info[basic_block[0]]['addr'],
            tail_addr=bb_info[basic_block[0]]['tail_addr'],
            executions=bb_info[basic_block[0]]['executions'],
            size=bb_info[basic_block[0]]['size'],
            insts=bb_info[basic_block[0]]['insts'],
            func=bb_info[basic_block[0]]['func']
        )

    # DCFG edges
    for edge in dcfg_json['PROCESSES'][1][1]['EDGES'][1:]:
      # if edge[1] in dcfg.nodes and edge[2] in dcfg.nodes:
      if edge[1] in dcfg.nodes and edge[2] in dcfg.nodes:
        dcfg.add_edge(edge[1], edge[2], type=edge_types[edge[3]], executions=edge[4], func=(
            dcfg.nodes[edge[1]]['func'], dcfg.nodes[edge[2]]['func']))

    return dcfg

  def __build_target_tid_dcfg(self, name):
    dcfg = getattr(self, f'{name}_full_dcfg')
    tids = getattr(self, f'{name}_tids')
    # Count executions within thread, remove edges if exection number is 0
    edges_to_remove = []
    for edge in dcfg.edges:
      executions = sum([dcfg[edge[0]][edge[1]]['executions'][i] for i in tids])
      dcfg[edge[0]][edge[1]]['executions'] = executions
      if executions == 0:
        edges_to_remove.append((edge[0], edge[1]))
    dcfg.remove_edges_from(edges_to_remove)

    # Update execution number of each node, as the executions of all incoming edges
    for node in dcfg.nodes:
      for e in dcfg.in_edges(node):
        # print(dcfg[e[0]][e[1]]['executions'])

        dcfg.nodes[node]['executions'] = sum(
            [dcfg[e[0]][e[1]]['executions'] for e in dcfg.in_edges(node)])

    # Update call probability of each edge
    for edge in dcfg.edges:
      if dcfg.nodes[edge[0]]['executions'] != 0:
        dcfg[edge[0]][edge[1]]['forward_prob'] = min(
            dcfg[edge[0]][edge[1]]['executions'] / dcfg.nodes[edge[0]]['executions'], 1.0)
      else:
        dcfg[edge[0]][edge[1]]['forward_prob'] = 1
      if dcfg.nodes[edge[1]]['executions'] != 0:
        dcfg[edge[0]][edge[1]]['backward_prob'] = min(
            dcfg[edge[0]][edge[1]]['executions'] / dcfg.nodes[edge[1]]['executions'], 1.0)
      else:
        dcfg[edge[0]][edge[1]]['backward_prob'] = 1

    return dcfg

  def __parse_basic_blocks(self, bb_lines):
    # Build basic block information
    basic_blocks = {}
    for line in bb_lines:
      if line.startswith("BLOCK"):
        bb_id = int(re.findall(r'(?<=\bBLOCK:\s)[0-9]+', line)[0])
        addr = re.findall(r'(?<=\bPC:\s)[0-9a-z]+', line)[0]
        basic_blocks[bb_id] = {"addr": addr, "insts": []}
      elif line.startswith("XDIS"):
        addr = re.findall(r'(?<=\bXDIS\s)[0-9a-z]+', line)[0]
        inst = re.findall(
            r'XDIS\s[0-9a-f]+:\s[A-Z0-9]+\s+[0-9a-f]+\s+([a-z0-9 ,\[\]\+\:\-\*]+)', line)[0]
        basic_blocks[bb_id]["insts"].append({"addr": addr, "inst": inst})
    return basic_blocks

  def __parse_x86operands(self):
    x86operands = {}
    for inst in self.x86insts:
      inst_name = inst['name']
      inst_operands = [
          {
              'type': operand['type'],
              'read': operand['read'],
              'write': operand['write'],
          } for operand in inst['operands']
      ]
      inst_operand_types = tuple()
      inst_rwx = tuple()
      for operand in inst_operands:
        if not operand['type']:
          inst_operand_types += (['imm'],)
          inst_rwx += ('', )
        elif operand['type'] == 'rel':
          inst_operand_types += (['imm'],)
          inst_rwx += ('', )
        else:
          if operand['type'] in ['mem', 'reg']:
            inst_operand_types += ([operand['type']],)
          else:
            assert operand['type'] in ['mem/reg', 'reg/mem']
            inst_operand_types += (['reg', 'mem'],)
          if operand['read'] and operand['write']:
            inst_rwx += ('x', )
          elif operand['read']:
            inst_rwx += ('r', )
          elif operand['write']:
            inst_rwx += ('w', )
          else:
            raise ValueError('Unsupported operand type')

      inst_operand_types_list = itertools.product(*inst_operand_types)
      if inst_name not in x86operands:
        x86operands[inst_name] = {}
      for inst_operand_types in inst_operand_types_list:
        if inst_operand_types in x86operands[inst_name]:
          assert x86operands[inst_name][inst_operand_types] == inst_rwx
        else:
          x86operands[inst_name][inst_operand_types] = inst_rwx
    return x86operands

  def __parse_x86regs(self):
    """
    Get all x86 registers
    """
    x86regs = set()
    for reg_group in self.x86data['registers']:
      for reg_name in self.x86data['registers'][reg_group]['names']:
        if '-' not in reg_name:
          x86regs.add(reg_name)
        else:
          reg_nums_str = re.findall(r'(\d+-\d+)', reg_name)[0]
          reg_nums_start_idx = reg_nums_str.split('-')[0]
          reg_nums_end_idx = reg_nums_str.split('-')[1]
          for i in range(int(reg_nums_start_idx), int(reg_nums_end_idx) + 1):
            x86regs.add(reg_name.replace(reg_nums_str, str(i)))
    return x86regs

  @abc.abstractmethod
  def run_analysis(self):
    """
    Analyze the data
    """
    pass
