from base_analyzer import BaseAnalyzer

class InstructionAnalyzer(BaseAnalyzer):
  """
  Analyse the size of each block.
  """

  def __init__(self, total_reqs, *kargs, **kwargs):
    super().__init__(parse_dcfg=True, *kargs, **kwargs)
    self.total_reqs = total_reqs

  def run_analysis(self):
    num_app_static_insts = 0
    num_app_dynamic_insts = 0
    num_skeleton_static_insts = 0
    num_skeleton_dynamic_insts = 0
    app_dynamic_inst_size = 0
    skeleton_dynamic_inst_size = 0
    app_static_inst_size = 0
    skeleton_static_inst_size = 0
    app_num_rep_static_insts = 0
    app_num_rep_dynamic_insts = 0

    for bb in self.app_dcfg.nodes():
      num_app_static_insts += self.app_dcfg.nodes[bb]['insts']
      num_app_dynamic_insts += self.app_dcfg.nodes[bb]['insts'] * self.app_dcfg.nodes[bb]['executions']
      app_static_inst_size += self.app_dcfg.nodes[bb]['size']
      app_dynamic_inst_size += self.app_dcfg.nodes[bb]['size'] * self.app_dcfg.nodes[bb]['executions']

      # rep insts
      if self.app_basic_blocks[bb]['insts'][0]['inst'].startswith('rep'):
        in_edge_executions = 0
        for edge in self.app_dcfg.in_edges(bb):
          if edge[0] != bb:
            in_edge_executions += self.app_dcfg.edges[edge]['executions']
        app_num_rep_static_insts += in_edge_executions
        app_num_rep_dynamic_insts += self.app_dcfg.nodes[bb]['executions']
      
    for bb in self.skeleton_dcfg.nodes():
      num_skeleton_static_insts += self.skeleton_dcfg.nodes[bb]['insts']
      num_skeleton_dynamic_insts += self.skeleton_dcfg.nodes[bb]['size'] * self.skeleton_dcfg.nodes[bb]['executions']
      skeleton_static_inst_size += self.skeleton_dcfg.nodes[bb]['size']
      skeleton_dynamic_inst_size += self.skeleton_dcfg.nodes[bb]['size'] * self.skeleton_dcfg.nodes[bb]['executions']
    
    mean_static_inst_size = (app_static_inst_size - skeleton_static_inst_size) / (num_app_static_insts - num_skeleton_static_insts)

    return {
      'num_static_insts': num_app_static_insts - num_skeleton_static_insts,
      'num_dynamic_insts': num_app_dynamic_insts - num_skeleton_dynamic_insts,
      'num_dynamic_insts_per_request': int((num_app_dynamic_insts - num_skeleton_dynamic_insts) / self.total_reqs),
      'mean_static_inst_size': mean_static_inst_size,
      'rep_num_static_insts': app_num_rep_static_insts,
      'rep_num_dynamic_insts': app_num_rep_dynamic_insts,
      'rep_num_dynamic_insts_per_request': int(app_num_rep_dynamic_insts / self.total_reqs),
    }