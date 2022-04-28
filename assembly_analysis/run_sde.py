import argparse
import subprocess as sp
import os
import logging
import yaml
import shlex
import time

SDE_BIN_PATH = 'PATH-TO-YOUR-SDE-BIN-DIR'

# Initiate logger
formatter = logging.Formatter('%(asctime)s [%(levelname)s]: %(message)s')
handler = logging.StreamHandler()
handler.setFormatter(formatter)
logger = logging.getLogger()
logger.handlers = []
logger.addHandler(handler)

# Command line arguments
parser = argparse.ArgumentParser(description='args for profiling')
parser.add_argument('-a', '--app', type=str, dest='app',
                    help='Application name', required=True)
parser.add_argument('-p', '--pid', type=int, dest='pid', 
                    help='Pid of the profiled process', required=True)
parser.add_argument('-o', '--output_path', dest='output_path',
                    default='./logs', help='Profiling output path')
parser.add_argument('-c', '--connection', dest='connection', type=int,
                    default=0, help='connection', required=True)
parser.add_argument('-q', '--qps', dest='qps', type=int,
                    default=0, help='QPS', required=True)
parser.add_argument('-d', '--duration', dest='duration', type=int,
                    default=0, help='duration', required=True)
parser.add_argument('--sde:itrace', dest='sde_itrace', action='store_true', 
                    default=False, help='Enable itrace in SDE')
parser.add_argument('--sde:mem_trace', dest='sde_mem_trace',
                    action='store_true', help='Enable mem_trace in SDE')
parser.add_argument('--debug', dest='debug',
                    action='store_true', help='Debug level logging')
args = parser.parse_args()

if args.debug:
  logger.setLevel(logging.DEBUG)
else:
  logger.setLevel(logging.INFO)

# Set up client and output directory
with open('profiling_configs.json') as f:
  configs = yaml.load(f, Loader=yaml.Loader)
configs = configs[args.app]

conns = args.connection
qps = args.qps
duration = args.duration

app_cmd = configs["app_cmd"]
if 'app_cwd' not in configs:
  app_cwd = os.path.dirname(configs["app_cmd"].split()[0])
else:
  app_cwd = configs["app_cwd"]

subdir = f'{args.app}_{qps}'
sde_data_dir = os.path.join(args.output_path, subdir, 'sde')
client_data_dir = os.path.join(args.output_path, subdir, 'client')
if not os.path.exists(sde_data_dir):
  os.makedirs(sde_data_dir)
if not os.path.exists(client_data_dir):
  os.makedirs(client_data_dir)

logging.info(f'Collecting SDE for {args.app}')
logging.info(f'Starting Intel SDE')

if args.sde_itrace:
  sde_cmd = (f'{SDE_BIN_PATH}/sde64 -dcfg 1 -dcfg:write_bb 1 -mix -iform 1 -itrace_compact 1 -top_blocks 0 '
            '-function_call_counts 0 -global_functions 0 -global_hot_blocks 0 '
            f'-line_info 0 -mix_omit_per_function_stats 1 -attach-pid {args.pid}')
elif args.sde_mem_trace:
  # TODO: add -mem_trace_file
  sde_cmd = (f'{SDE_BIN_PATH}/sde64 -debugtrace -data_watchpoint_memop_addr 1 -attach-pid {args.pid}')
else:
  sde_cmd = (f'{SDE_BIN_PATH}/sde64 -dcfg 1 -dcfg:write_bb 1 -mix -iform 1 -top_blocks 0 '
            '-function_call_counts 0 -global_functions 0 -global_hot_blocks 0 '
            f'-line_info 0 -mix_omit_per_function_stats 1 -attach-pid {args.pid}')
sde_proc = sp.Popen(shlex.split(sde_cmd), stdout=sp.PIPE, stderr=sp.PIPE)

logging.info(f'SDE runs {sde_cmd}')

stdout, stderr = sde_proc.communicate()
if sde_proc.returncode is not None and sde_proc.returncode != 0:
  err = stderr.decode()
  logging.fatal(
      f'Intel SDE failed. Return code: {sde_proc.returncode}. '
      f'Error message: {err}')
  exit(1)
else:
  logging.info(f'Intel SDE is running successfully')
time.sleep(1)

# Run client
client_cmd = (configs["client_cmd"]
            .replace('<conns>', str(conns))
            .replace('<reqs>', str(qps * duration))
            .replace('<duration>', str(duration))
            .replace('<reqs_per_sec>', str(int(qps)))
            .replace('<reqs_per_sec_per_conn>', str(int(qps / conns))))
logging.info(f'Starting client for profiling sde')
logging.info(f'Client runs {client_cmd}')
if 'sde_client_cwd' in configs:
  client_proc = sp.Popen(shlex.split(client_cmd), stdout=sp.PIPE, stderr=sp.PIPE, cwd=configs["sde_client_cwd"])
else:
  client_proc = sp.Popen(shlex.split(client_cmd), stdout=sp.PIPE, stderr=sp.PIPE)
stdout, stderr = client_proc.communicate()
if client_proc.returncode is not None and client_proc.returncode != 0:
  err = stderr.decode()
  logging.fatal(
      f'{args.app} failed to run client. Return code: '
      f'{client_proc.returncode}. Error message: {err}')
else:
  logging.info(f'{args.app} client ran successfully')
  with open(f'{client_data_dir}/client_sde.txt', 'w') as f:
    f.write(stdout.decode())
time.sleep(1)

# Kill job to get SDE results
logging.info(f'Killing {args.app}, PID = {args.pid}')
sp.check_call(f'Kill {args.pid}', shell=True)

dcfg_json_file = os.path.join(app_cwd, 'dcfg-out.dcfg.json')
dcfg_bb_file =  os.path.join(app_cwd, 'dcfg-out.bb.txt')
dcfg_json_bzip_file = os.path.join(app_cwd, 'dcfg-out.dcfg.json.bz2')
dcfg_bb_bzip_file =  os.path.join(app_cwd, 'dcfg-out.bb.txt.bz2')

if os.path.exists(dcfg_json_file):
  sp.check_call(f'rm {dcfg_json_file}', shell=True)
if os.path.exists(dcfg_bb_file):
  sp.check_call(f'rm {dcfg_bb_file}', shell=True)

while True:
  try:
    # Check if the process is still running
    sp.check_call(f'ps -p {args.pid}', shell=True, stdout=sp.DEVNULL, stderr=sp.DEVNULL)
    time.sleep(1)
  except sp.CalledProcessError:
    break

# Dump SDE and move to output directory
if args.sde_itrace:
  cmd = (f'mv sde-mix-out.txt {sde_data_dir}/sde-mix-out.txt && '
        f'mv sde-itrace-out*txt {sde_data_dir}')
  sp.check_call(cmd, shell=True)
else:
  cmd = f'mv sde-mix-out.txt {sde_data_dir}/sde-mix-out.txt'
  sp.check_call(cmd, shell=True)

cmd = f'bzip2 -d {dcfg_bb_bzip_file} {dcfg_json_bzip_file}'
sp.check_call(cmd, shell=True)
cmd = (f'mv {dcfg_bb_file} {sde_data_dir}/dcfg-out.bb.txt && '
        f'mv {dcfg_json_file} {sde_data_dir}/dcfg-out.dcfg.json')
sp.check_call(cmd, shell=True)
logging.info(f'Collecting SDE for {args.app} finished')