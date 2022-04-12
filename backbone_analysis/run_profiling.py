import getpass
import argparse
import json
import subprocess as sp
import shlex
import os
import time
import logging
from concurrent.futures import ThreadPoolExecutor
import yaml
try:
    from yaml import CLoader as Loader, CDumper as Dumper
except ImportError:
    from yaml import Loader, Dumper

formatter = logging.Formatter('%(asctime)s [%(levelname)s]: %(message)s')
handler = logging.StreamHandler()
handler.setFormatter(formatter)
logger = logging.getLogger()
logger.handlers = []
logger.addHandler(handler)

THREAD_POOL_SIZE = 32

parser = argparse.ArgumentParser(description='args for profiling')
parser.add_argument('-a', '--app', type=str, dest='app', help='Application name', required=True)
parser.add_argument('-p', '--pid', type=int, dest='pid', 
    help='Pid of the profiled process', required=False)
parser.add_argument('-o', '--output_path', dest='output_path',
                    default='./logs', help='Profiling output path')
parser.add_argument('--debug', dest='debug', action='store_true', help='Debug level logging')

args = parser.parse_args()

if args.debug:
  logger.setLevel(logging.DEBUG)
else:
  logger.setLevel(logging.INFO)

root_passwd = getpass.getpass(prompt='Password for sudo:')
try:
  sp.check_call(f'echo {root_passwd} | sudo -S ls', shell=True, stdout=sp.PIPE, stderr=sp.PIPE)
except sp.CalledProcessError:
  logging.fatal("Incorrect sudo password")
  exit(1)

output_dir = f"{args.output_path}/{args.app}"
os.makedirs(output_dir, exist_ok=True)

with open('profiling_configs.json') as f:
  configs = yaml.load(f, Loader=Loader)
configs = configs[args.app]

# Get all child processes
def get_child_pids(args):
  pgrep_proc = sp.Popen(f'pgrep -P {args.pid}', shell=True, stdout=sp.PIPE)
  pgrep_proc.wait()
  return [int(x) for x in pgrep_proc.stdout.read().decode("ascii").split()]

# Process stack information collected by perf.
def process_perf_script(pid, conns, reqs, duration):
  os.path.join(output_dir, f'conns_{conns}_reqs_{reqs}_duration_{duration}', 'stap_result.json')

  try:
    perf_record_file = os.path.join(output_dir, f'conns_{conns}_reqs_{reqs}_duration_{duration}', f'perf_record_pid_{pid}.data')
    perf_script_file = os.path.join(output_dir, f'conns_{conns}_reqs_{reqs}_duration_{duration}', f'perf_script_pid_{pid}.data')
    if "perf_max_stack" in configs:
      max_stack = configs["perf_max_stack"]
    else:
      max_stack = 64
    perf_script_cmd = f'echo {root_passwd} | sudo -S perf script --max-stack {max_stack} ' \
        f'-F comm,pid,tid,time,event,ip,sym,dso,trace -i {perf_record_file} > {perf_script_file}'
    perf_script_proc = sp.Popen(perf_script_cmd, shell=True, stdout=sp.PIPE, stderr=sp.PIPE)
    perf_script_proc.wait()

  except sp.CalledProcessError:
    logging.error(f'conns_{conns}_reqs_{reqs}_duration_{duration} perf script error')

  try:
    # Stack collapse
    process_stack_collapse_file = os.path.join(output_dir, 
        f'conns_{conns}_reqs_{reqs}_duration_{duration}', f'process_stack_collapse_pid_{pid}.txt')
    thread_stack_collapse_file = os.path.join(output_dir, 
        f'conns_{conns}_reqs_{reqs}_duration_{duration}', f'thread_stack_collapse_pid_{pid}.txt')
    stack_collapse_cmd = f'./stackcollapse-perf.pl --pid {perf_script_file} > {process_stack_collapse_file} && ' \
        f'./stackcollapse-perf.pl --pid --tid {perf_script_file} > {thread_stack_collapse_file}'
    stack_collapse_proc = sp.Popen(stack_collapse_cmd, shell=True, stdout=sp.PIPE, stderr=sp.PIPE)
    stack_collapse_proc.wait()
  except sp.CalledProcessError:
    logging.error(f'conns_{conns}_reqs_{reqs}_duration_{duration} stack collapse error')

child_pids = get_child_pids(args)
perf_script_procs = {}

thread_pool = ThreadPoolExecutor(THREAD_POOL_SIZE)
process_callstack_futures = {}

exp_config_list = []
for conns in configs["conns_list"]:
  exp_config_list.append((conns, configs["typical_reqs"], configs["typical_duration"]))
for reqs in configs["reqs_list"]:
  exp_config_list.append((configs["typical_conns"], reqs, configs["typical_duration"]))
for duration in configs["duration_list"]:
  exp_config_list.append((configs["typical_conns"], configs["typical_reqs"], duration))
exp_config_list = list(set(exp_config_list))

# Run profiling for thread clustering and syscall analysis.
for (conns, reqs, duration) in exp_config_list:
  os.makedirs(os.path.join(output_dir, f'conns_{conns}_reqs_{reqs}_duration_{duration}'), exist_ok=True)

  logging.info(f'conns = {conns}, reqs = {reqs}, duration = {duration}')
  stap_cmd = f'echo {root_passwd} | sudo -S stap -vg threads.stp -x {args.pid} ' \
      '-D MAXACTION=1000000 -D MAXMAPENTRIES=1000000 -B CONFIG_MODVERSIONS=y > tmp_stap.json'
  logger.debug(stap_cmd.replace(root_passwd, "root_passwd"))
  logger.info('Systemstap start running.')
  stap_proc = sp.Popen(stap_cmd, shell=True, stdout=sp.PIPE, stderr=sp.PIPE)

  # Check if systemtap has successfully run
  stap_run_flag = False
  while not stap_run_flag:
    for line in stap_proc.stderr:
      if "Pass 5: starting run." in line.decode("ascii"):
        stap_run_flag = True
        break
    time.sleep(1)
    logging.info('Waiting for systemtap to run ...')

  # Perf record call stacks
  perf_record_procs = {}
  for pid in [args.pid] + child_pids:
    perf_record_file = os.path.join(output_dir, f'conns_{conns}_reqs_{reqs}_duration_{duration}', f'perf_record_pid_{pid}.data')
    perf_record_cmd = f'echo {root_passwd} | sudo -S perf record --call-graph dwarf -F {configs["perf_freq"]} -p {pid} ' \
        f'-g --user-callchains -o {perf_record_file} -- sleep {duration + 15}'
    logging.debug(perf_record_cmd.replace(root_passwd, "root_passwd"))
    logging.info(f'Perf record (pid = {pid}) start running')
    perf_record_procs[pid] = sp.Popen(perf_record_cmd, shell=True, stdout=sp.PIPE, stderr=sp.PIPE)

  # Make sure everything has been running successfully
  time.sleep(10)

  # Run workload generator
  client_cmd = (configs["client_cmd"]
    .replace('<conns>', str(conns))
    .replace('<reqs>', str(reqs))
    .replace('<duration>', str(duration))
    .replace('<reqs_per_sec>', str(int(reqs / duration)))
    .replace('<reqs_per_sec_per_conn>', str(int(reqs / duration / conns))))
  logging.debug(client_cmd.replace(root_passwd, "root_passwd"))
  logging.info('client start')
  if 'client_cwd' in configs:
    client_proc = sp.Popen(client_cmd, shell=True, stdout=sp.PIPE, cwd=configs["client_cwd"])
  else:
    client_proc = sp.Popen(client_cmd, shell=True, stdout=sp.PIPE)
  client_proc.wait()
  logging.info('client finish')
  for pid in perf_record_procs.keys():
    perf_record_procs[pid].wait()
    logging.info(f'perf record (pid = {pid}) finish')

  # TODO: check if not using killall works
  try:
    sp.check_output(f"echo {root_passwd} | sudo -S killall stap", shell=True)
    sp.check_output(f"echo {root_passwd} | sudo -S chown {getpass.getuser()} tmp_stap.json", shell=True)
  except:
    print(stap_proc.stderr.read().decode("ascii"))
    raise
  stap_proc.wait()
  logging.info('stap finish')

  # Write systemtap results
  with open('tmp_stap.json') as stap_out_file:
    stap_result = yaml.load(stap_out_file, Loader=Loader)
  stap_result['conns'] = conns
  stap_result['reqs'] = reqs
  stap_result['duration'] = duration

  # Process perf results, some processes may not appear at the beginning.
  # pids = [args.pid] + child_pids
  pids = list(stap_result['processes'].keys())
  for pid in pids:
    process_callstack_future = thread_pool.submit(
        process_perf_script,
        pid, conns, reqs, duration
    )
    process_callstack_futures[pid, conns, reqs, duration] = process_callstack_future

  with open(os.path.join(output_dir, f'conns_{conns}_reqs_{reqs}_duration_{duration}', 'stap_result.json'), 'w') as f:
    json.dump(stap_result, f, indent=2)

for key, future in process_callstack_futures.items():
  future.result()
  logging.info(f'stack collapse {key} finished')

sp.check_output(f"rm tmp_stap.json", shell=True)