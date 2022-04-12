import itertools
import os
from concurrent.futures import ProcessPoolExecutor, thread
import re
from sklearn.cluster import AgglomerativeClustering
import numpy as np
import pandas as pd
from sklearn.linear_model import LinearRegression
from jsoncomment import JsonComment
import json
import pickle
import subprocess as sp
import hashlib
from disjoint_set import DisjointSet

THREAD_POOL_SIZE = 88
TREE_DISTANCE_APP = './tree-similarity/tree_distance'

T_FUNCTIONALITY = {
    'T_APP'                    : 1,
    'T_NETIO_LISTEN'           : 2,
    'T_NETIO_TCP_SEND'         : 4,
    'T_NETIO_TCP_RECV'         : 8,
    'T_DISKIO_SEND'            : 16,
    'T_DISKIO_RECV'            : 32,
    'T_POLL'                   : 64,
    'T_EPOLL'                  : 128,
    'T_SELECT'                 : 256,
    'T_CLONED'                 : 512,
    'T_CLONE'                  : 1024,
    'T_MASTER'                 : 2048,
}

json_parser = JsonComment(json)

class TreeNode:
  def __init__(self, label):
    self.label = label
    self.children = list()

  @staticmethod
  def get_children(node):
    return node.children

  @staticmethod
  def update_cost(node_a, node_b):
    func_a = node_a.label.split(' %%% ')[0]
    count_a = int(node_a.label.split(' %%% ')[1])
    func_b = node_b.label.split(' %%% ')[0]
    count_b = int(node_b.label.split(' %%% ')[1])
    return (count_a + count_b) * strdist(func_a, func_b)

  @staticmethod
  def insert_cost(node_a):
    return int(node_a.label.split(' %%% ')[1])

  @staticmethod
  def remove_cost(node_a):
    return int(node_a.label.split(' %%% ')[1])

  def add_child(self, node, before=False):
    if before:  
      self.children.insert(0, node)
    else:   
      self.children.append(node)
    return self

def strdist(a, b):
  if a == b:
      return 0
  else:
      return 1

class ClusterAnalyzer:
  def __init__(self, app, main_pid):
    self.app = app
    self.input_path = f'./logs/{self.app}'
    self.main_pid = main_pid
  
  def __read_stack_collapse_data(self, conns, reqs, duration, pid):
    def build_call_graph_helper(f, pid, thread):
      graphs = {}
      lines = f.readlines()
      if lines:
        for line in lines:
          words = line.split(' %%% ')[0].split(';')
          if len(words) > 1:
            key = tuple([int(i) for i in re.findall('[0-9]+', words[0].split('-')[-1])])
            words[0] = self.app
            count = int(line.split(' %%% ')[1])
            if key not in graphs:
              func_name_hashed = hashlib.sha1(words[0].encode("ascii")).hexdigest()[:16]
              graphs[key] = TreeNode(f'{func_name_hashed} %%% {count}')
            else:
              func_name = graphs[key].label.split(' %%% ')[0]
              prev_count = int(graphs[key].label.split(' %%% ')[1])
              graphs[key].label = f'{func_name} %%% {prev_count + count}'
            
            prev_node = graphs[key]
            for i in range(1, len(words)):
              func_name_hashed = hashlib.sha1(words[i].encode("ascii")).hexdigest()[:16]
              if func_name_hashed not in [child.label.split(' %%% ')[0] for child in prev_node.children]:
                curr_node = TreeNode(f'{func_name_hashed} %%% {count}')
                prev_node.add_child(curr_node)
                prev_node = curr_node
              else:
                for child in TreeNode.get_children(prev_node):
                  if func_name_hashed == child.label.split(' %%% ')[0]:
                    func_name = child.label.split(' %%% ')[0]
                    prev_count = int(child.label.split(' %%% ')[1])
                    child.label = f'{func_name} %%% {prev_count + count}'
                    prev_node = child
                    break
      else:
        if not thread:
          graphs[(pid,)] = TreeNode(f' %%% 0')
        else:
          graphs[(pid, pid)] = TreeNode(f' %%% 0')
      return graphs

    def merge(dict1, dict2):
      dict2.update(dict1)
      return dict2
    
    # Thread level stacks
    input_file = os.path.join(self.input_path, 
        f'conns_{conns}_reqs_{reqs}_duration_{duration}', f'thread_stack_collapse_pid_{pid}.txt')
    if os.path.exists(input_file):
      with open(input_file) as f:
        thread_graphs = build_call_graph_helper(f, pid, thread=True)
    else:
      thread_graphs = None

    # Process level stacks
    input_file = os.path.join(self.input_path, 
        f'conns_{conns}_reqs_{reqs}_duration_{duration}', f'process_stack_collapse_pid_{pid}.txt')
    if os.path.exists(input_file):
      with open(input_file) as f:
        process_graphs = build_call_graph_helper(f, pid, thread=False)
    else:
      process_graphs = None

    if process_graphs and thread_graphs:
      graphs = merge(process_graphs, thread_graphs)
      return graphs
    else:
      return None

  def __preprocess_data(self, configs):
    ''' Preprocess the input data and read the Systemtap results and function call stacks
    process_key := (conns, reqs, duration, pid_key)
    thread_key  := (conns, reqs, duration, tid_key)
    pid_key     := (pid, )
    tid_key     := (pid, tid)

    Args:
      configs: Configuration from the json file

    Returns:
      (dict, dict, dict, dict): A tuple of dictionaries
        - stap_results: key: (conns, reqs, duration), value: systemtap results
        - call_stack_dists: key: (process_key/thread_key, process_key/thread_key),
                            value: normalized weighted tree edit distance of two processes/threads
        - call_stacks: key: process_key/thread_key, value: collapsed call stacks
    '''
    def output_bracket_notation_helper(graph):
      s = f'{{{graph.label}'
      for c in graph.children:
        s += output_bracket_notation_helper(c)
      s += '}'
      return s

    try: 
      with open(os.path.join(self.input_path, 'analysis', 'stap_results.pkl'), 'rb') as f:
        stap_results = pickle.load(f)
      with open(os.path.join(self.input_path, 'analysis', 'call_stacks.pkl'), 'rb') as f:
        call_stacks = pickle.load(f)
      return stap_results, call_stacks

    except:
      stap_results = {}
      call_stacks = {}

      exp_config_list = []
      for conns in configs['conns_list']:
        exp_config_list.append((conns, configs['typical_reqs'], configs['typical_duration']))
      for reqs in configs['reqs_list']:
        exp_config_list.append((configs['typical_conns'], reqs, configs['typical_duration']))
      for duration in configs['duration_list']:
        exp_config_list.append((configs['typical_conns'], configs['typical_reqs'], duration))
      exp_config_list = list(set(exp_config_list))

      for (conns, reqs, duration) in exp_config_list:
        f = open(os.path.join(self.input_path, f'conns_{conns}_reqs_{reqs}_duration_{duration}', 'stap_result.json'))
        stap_result = json_parser.load(f)
        f.close()
        stap_results[(conns, reqs, duration)] = stap_result
        for pid in stap_result['processes'].keys():
          graphs = self.__read_stack_collapse_data(conns, reqs, duration, pid)
          if not graphs:
            continue
          for key in graphs.keys():
            os.makedirs(os.path.join(self.input_path, 'analysis', f'conns_{conns}_reqs_{reqs}_duration_{duration}'), exist_ok=True)
            if len(key) == 1:
              output_file = os.path.join(self.input_path, 'analysis',
                  f'conns_{conns}_reqs_{reqs}_duration_{duration}', f'process_stack_collapse_pid_{key[0]}.txt')
            else:
              output_file = os.path.join(self.input_path, 'analysis',
                  f'conns_{conns}_reqs_{reqs}_duration_{duration}', f'thread_stack_collapse_tid_{key[1]}.txt')
            with open(output_file, 'w') as f:
              f.write(output_bracket_notation_helper(graphs[key]))
          for key, value in graphs.items():
            call_stacks[(conns, reqs, duration, key)] = value

      with open(os.path.join(self.input_path, 'analysis', 'stap_results.pkl'), 'wb') as f:
        pickle.dump(stap_results, f) 
      with open(os.path.join(self.input_path, 'analysis', 'call_stacks.pkl'), 'wb') as f:
        pickle.dump(call_stacks, f) 

      return stap_results, call_stacks

  def __call_stack_cluster(self, keys, thread_mode, threshold=0.2):
  
    def build_dist_matrix(call_stack_dists, keys):
      dist_matrix = np.zeros((len(keys), len(keys)))
      for key0, key1 in itertools.product(keys, repeat=2):
        if key0 == key1:
          dist_matrix[keys.index(key0)][keys.index(key1)] = 0
        else:
          dist_matrix[keys.index(key0)][keys.index(key1)] = call_stack_dists[(key0, key1)]
      return dist_matrix

    # Phase 1 cluster within each run
    # Calculate intra-run call stack distances
    try:
      if thread_mode:
        with open(os.path.join(self.input_path, 'analysis', f'thread_intra_call_stack_dists.pkl'), 'rb') as f:
          intra_call_stack_dists = pickle.load(f)
      else:
        with open(os.path.join(self.input_path, 'analysis', f'process_intra_call_stack_dists.pkl'), 'rb') as f:
          intra_call_stack_dists = pickle.load(f)
    except:
      intra_call_stack_dists = {}
      futures = {}
      run_args = list(set([(key[0], key[1], key[2]) for key in keys]))
      with ProcessPoolExecutor(max_workers=THREAD_POOL_SIZE) as e:
        for run_arg in run_args:
          intra_call_stack_dists[run_arg] = {}
          intra_keys = [key for key in keys if (key[0], key[1], key[2]) == run_arg]
          for key0, key1 in itertools.combinations(intra_keys, 2):
            if thread_mode:
              tree_file_0 = os.path.join(self.input_path, 'analysis', 
                  f'conns_{key0[0]}_reqs_{key0[1]}_duration_{key0[2]}', f'thread_stack_collapse_tid_{key0[3][1]}.txt')
              tree_file_1 = os.path.join(self.input_path, 'analysis', 
                  f'conns_{key1[0]}_reqs_{key1[1]}_duration_{key1[2]}', f'thread_stack_collapse_tid_{key1[3][1]}.txt')
            else:
              tree_file_0 = os.path.join(self.input_path, 'analysis', 
                  f'conns_{key0[0]}_reqs_{key0[1]}_duration_{key0[2]}', f'process_stack_collapse_pid_{key0[3][0]}.txt')
              tree_file_1 = os.path.join(self.input_path, 'analysis', 
                  f'conns_{key1[0]}_reqs_{key1[1]}_duration_{key1[2]}', f'process_stack_collapse_pid_{key1[3][0]}.txt')
            
            cmd = f"{TREE_DISTANCE_APP} {tree_file_0} {tree_file_1}"
            futures[(key0, key1)] = e.submit(sp.run, cmd, stdout=sp.PIPE, shell=True)

        for run_arg in run_args:
          intra_keys = [key for key in keys if (key[0], key[1], key[2]) == run_arg]
          for key0, key1 in itertools.combinations(intra_keys, 2):
            result = float(futures[(key0, key1)].result().stdout.decode('ascii'))
            intra_call_stack_dists[(key0[0], key0[1], key0[2])][(key0, key1)] = result
            intra_call_stack_dists[(key0[0], key0[1], key0[2])][(key1, key0)] = result
            # intra_call_stack_dists[(key0[0], key0[1], key0[2])][(key1, key0)] = intra_call_stack_dists[(key0[0], key0[1], key0[2])][(key0, key1)]

      if thread_mode:
        with open(os.path.join(self.input_path, 'analysis', f'thread_intra_call_stack_dists.pkl'), 'wb') as f:
          pickle.dump(intra_call_stack_dists, f)
      else:
        with open(os.path.join(self.input_path, 'analysis', f'process_intra_call_stack_dists.pkl'), 'wb') as f:
          pickle.dump(intra_call_stack_dists, f)

    # Cluster
    intra_dist_matrix = {}
    intra_clusters = {}
    for run_arg in intra_call_stack_dists:
      intra_clusters[run_arg] = {}
      intra_keys = [key for key in keys if (key[0], key[1], key[2]) == run_arg]
      if len(intra_keys) > 1:
        intra_dist_matrix[run_arg] = build_dist_matrix(intra_call_stack_dists[run_arg], intra_keys)
        clustering = AgglomerativeClustering(
            n_clusters=None, 
            affinity='precomputed',
            linkage='average',
            distance_threshold=threshold).fit(intra_dist_matrix[run_arg])
        clustering_labels = list(clustering.labels_)
        for i in range(len(clustering_labels)):
          if clustering_labels[i] not in intra_clusters[run_arg]:
            intra_clusters[run_arg][clustering_labels[i]] = [intra_keys[i]]
          else:
            intra_clusters[run_arg][clustering_labels[i]] += [intra_keys[i]]
      else:
        intra_clusters[run_arg][0] = intra_keys

    # Phase 2 cluster across all experiments
    try:
      if thread_mode:
        with open(os.path.join(self.input_path, 'analysis', f'thread_inter_call_stack_dists.pkl'), 'rb') as f:
          inter_call_stack_dists = pickle.load(f)
      else:
        with open(os.path.join(self.input_path, 'analysis', f'process_inter_call_stack_dists.pkl'), 'rb') as f:
          inter_call_stack_dists = pickle.load(f)
    except:
      inter_call_stack_dists = {}
      futures = {}
      run_args = list(set([(key[0], key[1], key[2]) for key in keys]))
      inter_keys = []
      cluster_labals = {}
      for run_arg in run_args:
        cluster_labals[run_arg] = {}
        for cluster_labal in intra_clusters[run_arg]:
          inter_keys.append(intra_clusters[run_arg][cluster_labal][0])
      with ProcessPoolExecutor(max_workers=THREAD_POOL_SIZE) as e:
        for key0, key1 in itertools.combinations(inter_keys, 2):
          if thread_mode:
            tree_file_0 = os.path.join(self.input_path, 'analysis', 
                f'conns_{key0[0]}_reqs_{key0[1]}_duration_{key0[2]}', f'thread_stack_collapse_tid_{key0[3][1]}.txt')
            tree_file_1 = os.path.join(self.input_path, 'analysis', 
                f'conns_{key1[0]}_reqs_{key1[1]}_duration_{key1[2]}', f'thread_stack_collapse_tid_{key1[3][1]}.txt')
          else:
            tree_file_0 = os.path.join(self.input_path, 'analysis', 
                f'conns_{key0[0]}_reqs_{key0[1]}_duration_{key0[2]}', f'process_stack_collapse_pid_{key0[3][0]}.txt')
            tree_file_1 = os.path.join(self.input_path, 'analysis', 
                f'conns_{key1[0]}_reqs_{key1[1]}_duration_{key1[2]}', f'process_stack_collapse_pid_{key1[3][0]}.txt')
          
          cmd = f"{TREE_DISTANCE_APP} {tree_file_0} {tree_file_1}"
          futures[(key0, key1)] = e.submit(sp.run, cmd, stdout=sp.PIPE, shell=True)
        for key0, key1 in itertools.combinations(inter_keys, 2):
          result = float(futures[(key0, key1)].result().stdout.decode('ascii'))
          inter_call_stack_dists[(key0, key1)] = result
          inter_call_stack_dists[(key1, key0)] = result
      if thread_mode:
        with open(os.path.join(self.input_path, 'analysis', f'thread_inter_call_stack_dists.pkl'), 'wb') as f:
          pickle.dump(inter_call_stack_dists, f) 
      else:
        with open(os.path.join(self.input_path, 'analysis', f'process_inter_call_stack_dists.pkl'), 'wb') as f:
          pickle.dump(inter_call_stack_dists, f) 

    # Cluster
    inter_clusters = {}
    intra_cluster_labals = {}
    inter_keys = []
    run_args = list(set([(key[0], key[1], key[2]) for key in keys]))
    for run_arg in run_args:
      intra_cluster_labals[run_arg] = {}
      for cluster_labal in intra_clusters[run_arg]:
        inter_keys.append(intra_clusters[run_arg][cluster_labal][0])
        intra_cluster_labals[run_arg][intra_clusters[run_arg][cluster_labal][0]] = cluster_labal
    if len(inter_keys) > 1:
      inter_dist_matrix = build_dist_matrix(inter_call_stack_dists, inter_keys)
      clustering = AgglomerativeClustering(
          n_clusters=None, 
          affinity='precomputed',
          linkage='average',
          distance_threshold=threshold).fit(inter_dist_matrix)
      clustering_labels = list(clustering.labels_)

      for i in range(len(clustering_labels)):
        run_arg = (inter_keys[i][0], inter_keys[i][1], inter_keys[i][2])
        if clustering_labels[i] not in inter_clusters:
          inter_clusters[clustering_labels[i]] = intra_clusters[run_arg][intra_cluster_labals[run_arg][inter_keys[i]]]
        else:
          inter_clusters[clustering_labels[i]] += intra_clusters[run_arg][intra_cluster_labals[run_arg][inter_keys[i]]]
    else:
      intra_clusters[0] = intra_clusters[run_arg][intra_cluster_labals[run_arg][inter_keys[0]]]

    # Phase 3 collapse clusters with same pid
    inter_cluster_ds = DisjointSet()
    for cluster_labal in inter_clusters:
      if len(inter_clusters[cluster_labal]) == 1:
        inter_cluster_ds.find(inter_clusters[cluster_labal][0])
      for key0, key1 in itertools.combinations(inter_clusters[cluster_labal], 2):
        inter_cluster_ds.union(key0, key1)
    
    for key0, key1 in itertools.combinations(keys, 2):
      if key0[3] == key1[3]:
        inter_cluster_ds.union(key0, key1)

    inter_cluster_list = list(inter_cluster_ds.itersets())
    inter_clusters = {}
    for i in range(len(inter_cluster_list)):
      inter_clusters[i] = list(inter_cluster_list[i])

    return inter_clusters

  # Filter out clusters if it does not exist in most of experiments, which may be because of instrumentation exceptions.
  def __filter_clusters(self, clusters, run_args, threshold=0.5):
    del_labels = []
    for cluster_label in clusters:
      exist_run_args = []
      for key in clusters[cluster_label]:
        if (key[0], key[1], key[2]) not in exist_run_args:
          exist_run_args.append((key[0], key[1], key[2]))
      if len(exist_run_args) < threshold * len(run_args):
        del_labels.append(cluster_label)
        
    for label in del_labels:
      del clusters[label]

    return clusters

  def __cluster_characterization(self, configs, stap_results, clusters):

    def count_helper(clusters, cluster_label, r2_threshold=0.9):
      counts = {}
      df = pd.DataFrame(columns=['conns', 'reqs', 'duration', 'count'])
      for (conns, reqs, duration, key) in clusters[cluster_label]:
        if (conns, reqs, duration) not in counts:
          counts[(conns, reqs, duration)] = 1
        else:
          counts[(conns, reqs, duration)] += 1
      for key, value in counts.items():
        df = df.append({'conns': key[0], 'reqs': key[1], 'duration': key[2], 'count': value}, ignore_index=True)
      linear_relationship = {}
      for col_x in ['conns', 'reqs', 'duration']:
        model = LinearRegression()
        if col_x == 'conns':
          X = df[df['reqs'].eq(configs['typical_reqs']) & df['duration'].eq(configs['typical_duration'])][col_x].to_numpy().reshape(-1, 1)
          y = df[df['reqs'].eq(configs['typical_reqs']) & df['duration'].eq(configs['typical_duration'])]['count'].to_numpy().reshape(-1, 1)
        elif col_x == 'reqs':
          X = df[df['conns'].eq(configs['typical_conns']) & df['duration'].eq(configs['typical_duration'])][col_x].to_numpy().reshape(-1, 1)
          y = df[df['conns'].eq(configs['typical_conns']) & df['duration'].eq(configs['typical_duration'])]['count'].to_numpy().reshape(-1, 1)
        else:
          X = df[df['conns'].eq(configs['typical_conns']) & df['reqs'].eq(configs['typical_reqs'])][col_x].to_numpy().reshape(-1, 1)
          y = df[df['conns'].eq(configs['typical_conns']) & df['reqs'].eq(configs['typical_reqs'])]['count'].to_numpy().reshape(-1, 1)
        try:
          reg = model.fit(X, y)
          if reg.score(X, y) > r2_threshold:
            linear_relationship[col_x] = {'coef': float(reg.coef_[0][0]), 'intercept': float(reg.intercept_[0])}
          else:
            linear_relationship[col_x] = {'coef': 0.0, 'intercept': float(df['count'].max())}
        except ValueError:
          pass
      
      return linear_relationship

    def functionality_helper(stap_results, clusters, cluster_label):
      def most_frequent(l): 
        max_count = 0
        num = l[0]
        max_count = 0
          
        for i in l: 
          curr_frequency = l.count(i) 
          if(curr_frequency > max_count): 
            max_count = curr_frequency 
            num = i 
        return num, max_count / len(l)

      if len(clusters[cluster_label][0][3]) == 1: 
        # The cluster is a process cluster
        functionality_list = [stap_results[key[0], key[1], key[2]]['processes'][str(key[3][0])]['type'] 
            for key in clusters[cluster_label]]
      elif len(clusters[cluster_label][0][3]) == 2: 
        # The cluster is a thread cluster
        functionality_list = []
        for key in clusters[cluster_label]:
          try: 
            functionality_list.append(stap_results[key[0], key[1], key[2]]['threads'][str(key[3][1])]['type'] )
          except KeyError:
            # The thread is not captured by systemtap due to lack of useful work
            functionality_list.append(1)
      
      func, freq = most_frequent(functionality_list)
      return {'functionality': func, 'functionality_freq': freq}

    def call_freq_helper(stap_results, clusters, cluster_label, r2_threshold=0.95):
      df = pd.DataFrame(columns=['conns', 'reqs', 'duration', 'num_ctx_switch'])
      for key in clusters[cluster_label]:
        if len(clusters[cluster_label][0][3]) == 1: 
          # The cluster is a process cluster
          num_ctx_switch = stap_results[key[0], key[1], key[2]]['processes'][str(key[3][0])]['num_ctx_switch'] 
        elif len(clusters[cluster_label][0][3]) == 2: 
          # The cluster is a thread cluster
          try: 
            num_ctx_switch = stap_results[key[0], key[1], key[2]]['threads'][str(key[3][1])]['num_ctx_switch']
          except KeyError:
            # The thread is not captured by systemtap due to lack of useful work
            num_ctx_switch = 0

        df = df.append({'conns': key[0], 'reqs': key[1], 'duration': key[2], 
            'num_ctx_switch': int(num_ctx_switch)}, ignore_index=True)

      df = df.astype('int32')
      df = df.groupby(['conns', 'reqs', 'duration']).sum().reset_index()
      linear_relationship = {}
      for col_x in ['conns', 'reqs', 'duration']:
        model = LinearRegression()
        if col_x == 'conns':
          X = df[df['reqs'].eq(configs['typical_reqs']) & df['duration'].eq(configs['typical_duration'])][col_x].to_numpy().reshape(-1, 1)
          y = df[df['reqs'].eq(configs['typical_reqs']) & df['duration'].eq(configs['typical_duration'])]['num_ctx_switch'].to_numpy().reshape(-1, 1)
        elif col_x == 'reqs':
          X = df[df['conns'].eq(configs['typical_conns']) & df['duration'].eq(configs['typical_duration'])][col_x].to_numpy().reshape(-1, 1)
          y = df[df['conns'].eq(configs['typical_conns']) & df['duration'].eq(configs['typical_duration'])]['num_ctx_switch'].to_numpy().reshape(-1, 1)
        else:
          X = df[df['conns'].eq(configs['typical_conns']) & df['reqs'].eq(configs['typical_reqs'])][col_x].to_numpy().reshape(-1, 1)
          y = df[df['conns'].eq(configs['typical_conns']) & df['reqs'].eq(configs['typical_reqs'])]['num_ctx_switch'].to_numpy().reshape(-1, 1)
        try:
          reg = model.fit(X, y)
          if reg.score(X, y) > r2_threshold:
            linear_relationship[col_x] = {'coef': float(reg.coef_[0][0]), 'intercept': float(reg.intercept_[0])}
          else:
            linear_relationship[col_x] = {'coef': 0.0, 'intercept': float(df['num_ctx_switch'].mean())}
        except ValueError:
          pass
      return linear_relationship
    
    def socket_settings_helper(stap_results, clusters, cluster_label):
      socket_settings = []
      for (conns, reqs, duration, key) in clusters[cluster_label]:
        stap_result = stap_results[(conns, reqs, duration)]
        fds = stap_result['fds']
        # Thread cluster
        if len(key) == 2:
          pid, tid = int(key[0]), int(key[1])
          for fd in fds.keys():
            if fds[fd]['mode'] != 'S_IFSOCK':
              continue
            pid_field, tid_field = int(fd.split(",")[0]), int(fd.split(",")[1])
            if pid_field == pid and tid_field == tid:
              socket_settings.append(fds[fd]['flag'])
        else:
          # Process cluster
          pid = int(key[0])
          for fd in fds.keys():
            if fds[fd]['mode'] != 'S_IFSOCK':
              continue
            pid_field = int(fd.split(",")[0])
            if pid_field == pid:
              socket_settings.append(fds[fd]['flag'])
      return list(set(socket_settings))

    global T_FUNCTIONALITY

    cluster_characterizations = {}
    for cluster_label in clusters:
      count = count_helper(clusters, cluster_label)
      functionality = functionality_helper(stap_results, clusters, cluster_label)
      call_freq = call_freq_helper(stap_results, clusters, cluster_label)
      socket_settings = socket_settings_helper(stap_results, clusters, cluster_label)
      
      functionality_str = ''
      for t_tunc in T_FUNCTIONALITY:
        if functionality['functionality'] & T_FUNCTIONALITY[t_tunc]:
          functionality_str += f'{t_tunc}, '
      functionality_str = functionality_str[:-2]

      cluster_characterizations[str(cluster_label)] = {
          'count': count,
          'func': {'functionality': functionality_str, 'functionality_freq': functionality['functionality_freq']},
          'call_freq': call_freq,
          'socket_settings': socket_settings,
          'pids/tids': list(set([key[3] for key in clusters[cluster_label]]))
      }
      
    return cluster_characterizations

  def run_analyze_cluster(self, configs, thread_mode=True):
    os.makedirs(os.path.join(self.input_path, 'analysis'), exist_ok=True)
    stap_results, call_stacks = self.__preprocess_data(configs)
    thread_keys = [key for key in call_stacks.keys() if len(key[3]) == 2]
    run_args = list(set([(key[0], key[1], key[2]) for key in thread_keys]))

    # The threshold we use in AgglomerativeClustering to cluster threads/processes.
    cluster_threshold = 0.2
    if self.app == "mongod":
      cluster_threshold = 0.5

    if thread_mode:
      thread_clusters = self.__call_stack_cluster(thread_keys, thread_mode, threshold=cluster_threshold)
      thread_clusters = self.__filter_clusters(thread_clusters, run_args, threshold=0.5)
      thread_characteristics = self.__cluster_characterization(configs, stap_results, thread_clusters)
      return thread_characteristics, stap_results
    else:
      if len(stap_results[(configs['typical_conns'], configs['typical_reqs'], configs['typical_duration'])]["processes"]) > 1: 
        process_keys = [key for key in call_stacks.keys() if len(key[3]) == 1]
        process_clusters = self.__call_stack_cluster(call_stacks, process_keys, thread_mode, threshold=cluster_threshold)
        process_clusters = self.__filter_clusters(process_clusters, run_args, threshold=0.5)
        process_characteristics = self.__cluster_characterization(stap_results, process_clusters)
        return process_characteristics, stap_results
      else:
        return None, stap_results