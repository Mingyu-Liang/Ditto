from base_analyzer import BaseAnalyzer

BRANCH_INSTS = [
    'ja', 'jae', 'jb', 'jbe', 'jc', 'je', 'jg', 'jge', 'jl', 'jle', 'jna',
    'jnae', 'jnb', 'jnbe', 'jnc', 'jne', 'jng', 'jnge', 'jnl', 'jnle', 'jno',
    'jnp', 'jns', 'jnz', 'jo', 'jp', 'jpe', 'jpo', 'js', 'jz', 'jmp'
]

class BranchAnalyzer(BaseAnalyzer):
  """
  Profile the branch taken rate and branch transition rate.
  """

  def __init__(self, ignore_transition=False, *kargs, **kwargs):
    if ignore_transition:
      super().__init__(parse_dcfg=True, *kargs, **kwargs)
    else:
      super().__init__(parse_dcfg=True, parse_itrace=True, *kargs, **kwargs)
    self.ignore_transition = ignore_transition

  def profile_branch_taken_rate(self, name):
    dcfg = getattr(self, f'{name}_dcfg')
    branch_taken_rates = {}
    for edge_id in dcfg.edges:
      src_bb = edge_id[0]
      dst_bb = edge_id[1]
      # Direct and indirect conditional branches
      if dcfg.edges[edge_id]['type'] in ['DIRECT_CONDITIONAL_BRANCH', 'INDIRECT_CONDITIONAL_BRANCH']:
        prob = dcfg.edges[edge_id]['forward_prob']
        exectutions = dcfg.nodes[src_bb]['executions']
        if exectutions > 0:
          if src_bb not in branch_taken_rates:
            branch_taken_rates[src_bb] = {
                'taken_rates': prob,
                'executions': exectutions
            }
          else:
            branch_taken_rates[src_bb]['taken_rates'] += prob
    return branch_taken_rates

  def profile_branch_transition(self, name, prob_threashold=[1 / 32, 1 - 1 / 32]):
    """
    Args:
      prob_threashold: The lower bound and upper bound of branch taken 
          probability. Then branches within the range needs to be considered. 
    """

    def count_transitions_helper(transition_list):
      transition_count = 0
      prev_state = transition_list[0]
      if len(transition_list) > 1:
        for state in transition_list[1:]:
          if state != prev_state:
            transition_count += 1
            prev_state = state
      return transition_count

    dcfg = getattr(self, f'{name}_dcfg')
    itraces = getattr(self, f'{name}_itraces')

    # First block address to bb_id
    addr_to_bb_id = {}
    for bb_id in dcfg.nodes:
      addr_to_bb_id[dcfg.nodes[bb_id]['addr']] = bb_id

    branch_transitions = {}
    for tid, itrace in itraces.items():
      if name == 'skeleton' or tid in self.app_tids:
        for i in range(len(itrace) - 2):
          curr_line = itrace[i].split('0x')[1][:-1]
          next_line = itrace[i + 1].split('0x')[1][:-1]
          curr_bb = addr_to_bb_id[curr_line]
          next_bb = addr_to_bb_id[next_line]
          if curr_bb not in branch_transitions:
            branch_transitions[curr_bb] = []
          if (curr_bb, next_bb) in dcfg.edges:
            if dcfg.edges[(curr_bb, next_bb)]['type'] in ['DIRECT_CONDITIONAL_BRANCH', 'INDIRECT_CONDITIONAL_BRANCH']:
              branch_transitions[curr_bb].append('T')
            elif dcfg.edges[(curr_bb, next_bb)]['type'] in ['FALL_THROUGH']:
              branch_transitions[curr_bb].append('NT')
          else:
            # TODO: Make sure there is no branch in between
            branch_transitions[curr_bb].append('NT')

    branch_transition_rates = {}
    for bb_id in branch_transitions:
      branch_transition_rates[bb_id] = count_transitions_helper(
          branch_transitions[bb_id]) / len(branch_transitions[bb_id])

    return branch_transition_rates

  def __cal_stats(self, name):
    def determine_bin_helper(bins, val):
      for i in range(len(bins) - 1):
        if abs(val - bins[i]) < abs(val - bins[i + 1]):
          return bins[i]
      return 0

    branch_taken_rates = getattr(self, f'{name}_branch_taken_rates')
    stats = {}
    taken_bins = [2 ** -i for i in range(1, 8)] + [0]
    if not self.ignore_transition:
      branch_transition_rates = getattr(self, f'{name}_branch_transition_rates')
      transition_bins = [2 ** -i for i in range(0, 8)] + [0]

    for bb_id in branch_taken_rates:
      taken_rate = (branch_taken_rates[bb_id]['taken_rates'] if branch_taken_rates[bb_id]
                    ['taken_rates'] < 0.5 else 1 - branch_taken_rates[bb_id]['taken_rates'])
      taken_bin = determine_bin_helper(taken_bins, taken_rate)
      if not self.ignore_transition:
        if bb_id in branch_transition_rates:
          transition_rate = branch_transition_rates[bb_id]
        else:
          transition_rate = 0
        transition_bin = determine_bin_helper(transition_bins, transition_rate)
        if (taken_bin, transition_bin) not in stats:
          stats[(taken_bin, transition_bin)] = branch_taken_rates[bb_id]['executions']
        else:
          stats[(taken_bin, transition_bin)
                ] += branch_taken_rates[bb_id]['executions']
      else:
        if (taken_bin, 0) not in stats:
          stats[(taken_bin, 0)] = branch_taken_rates[bb_id]['executions']
        else:
          stats[(taken_bin, 0)] += branch_taken_rates[bb_id]['executions']
    return stats

  def run_analysis(self):
    self.app_branch_taken_rates = self.profile_branch_taken_rate('app')
    self.skeleton_branch_taken_rates = self.profile_branch_taken_rate('skeleton')
    if not self.ignore_transition:
      self.app_branch_transition_rates = self.profile_branch_transition('app')
      self.skeleton_branch_transition_rates = self.profile_branch_transition('skeleton')

    stats = {}
    app_stats = self.__cal_stats('app')
    skeleton_stats = self.__cal_stats('skeleton')

    for taken_bin in [2 ** -i for i in range(1, 8)] + [0]:
      if self.ignore_transition:
        key = (taken_bin, 0)
        if key in app_stats and key in skeleton_stats:
          stats[key] = float(max(0, app_stats[key] - skeleton_stats[key]))
        elif key in app_stats:
          stats[key] = float(app_stats[key])
        elif key in skeleton_stats:
          stats[key] = 0.0
        else:
          stats[key] = 0.0
      else:
        for transition_bin in [2 ** -i for i in range(0, 8)] + [0]:
          key = (taken_bin, transition_bin)
          if key in app_stats and key in skeleton_stats:
            stats[key] = float(max(0, app_stats[key] - skeleton_stats[key]))
          elif key in app_stats:
            stats[key] = float(app_stats[key])
          elif key in skeleton_stats:
            stats[key] = 0.0
          else:
            stats[key] = 0.0
    
    s = sum(stats.values())
    if not s:
      return {(0, 0): 1.0}

    for key in stats:
      stats[key] /= s
    return stats