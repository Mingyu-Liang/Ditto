import argparse
import json
from jsoncomment import JsonComment
from analyze_cluster import ClusterAnalyzer
from analyze_syscall import SyscallAnalyzer
from analyze_network_model import NetworkModelAnalyzer

json_parser = JsonComment(json)

parser = argparse.ArgumentParser(description='args for analysis')
parser.add_argument('-a', '--app', type=str, dest='app', help='Application name', required=True)
parser.add_argument('-p', '--pid', type=int, dest='pid', 
    help='Pid of the profiled main process', required=True)
args = parser.parse_args()

with open('profiling_configs.json') as f:
  configs = json_parser.load(f)
configs = configs[args.app]

cluster_analyzer = ClusterAnalyzer(args.app, args.pid)
thread_characteristics, stap_results = cluster_analyzer.run_analyze_cluster(configs, thread_mode=True)

output = {}
output['thread_characteristics'] = thread_characteristics
network_threads = []
for thread in thread_characteristics:
  if "T_NETIO_TCP_SEND" in thread_characteristics[thread]["func"]["functionality"]:
    for pid_tid in thread_characteristics[thread]["pids/tids"]:
      network_threads.append(pid_tid[1])
# Currently we only consider syscalls invoked by network threads.
syscall_analyzer = SyscallAnalyzer(stap_results[(configs['typical_conns'], configs['typical_reqs'], configs['typical_duration'])], network_threads)
output['syscall_characteristics'] = syscall_analyzer.analyze_syscalls()
network_model_analyzer = NetworkModelAnalyzer(thread_characteristics, args.pid)
output['network_model_characteristics'] = network_model_analyzer.analyze_network_model()
print(json.dumps(output, indent=2))