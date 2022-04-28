import argparse
import subprocess as sp
import os
import time
import logging
import yaml
import shlex
import signal
import itertools

VALGRIND_BIN_PATH = 'PATH-TO-YOUR-VALGRIND-BIN-DIR'

# Here is an example that we simulate the cache size from 64B to 256MB
# and associativity as 8. You may want to change this for your own use case.
CACHELINE_SIZE = 64
CACHE_SIZES = []
cache_size_init = 64
cache_size_max = 256 * (1 << 20)
while cache_size_init <= cache_size_max:
  CACHE_SIZES.append(cache_size_init)
  cache_size_init *= 2
ASSOCIATIVITIES = [8]

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
parser.add_argument('-o', '--output_path', dest='output_path',
                    default='./logs', help='Profiling output path')
parser.add_argument('-c', '--connection', dest='connection', type=int,
                    default=0, help='connection', required=True)
parser.add_argument('-q', '--qps', dest='qps', type=int,
                    default=0, help='QPS', required=True)
parser.add_argument('-d', '--duration', dest='duration', type=int,
                    default=0, help='duration', required=True)
parser.add_argument('-l', '--load_data', dest='load_data', action='store_true',
                    default=False, help='Load data')
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
valgrind_data_dir = os.path.join(args.output_path, subdir, 'valgrind')
client_data_dir = os.path.join(args.output_path, subdir, 'client')
if not os.path.exists(valgrind_data_dir):
  os.makedirs(valgrind_data_dir)
if not os.path.exists(client_data_dir):
  os.makedirs(client_data_dir)

logging.info(f'Starting valgrind_cache for {args.app}')
valgrind_dcache_results = {}
valgrind_icache_results = {}
valgrind_bin = os.path.join(VALGRIND_BIN_PATH, 'valgrind')
callgrind_control_bin = os.path.join(VALGRIND_BIN_PATH, 'callgrind_control')

for cache_size, associativity in itertools.product(CACHE_SIZES, ASSOCIATIVITIES):
  if associativity * CACHELINE_SIZE > cache_size:
    associativity = int(cache_size / CACHELINE_SIZE)
  logging.info(f'Running valgrind_cache for {cache_size} {associativity}')

  valgrind_cmd = (f'{valgrind_bin} --tool=callgrind --dump-line=no --trace-children=yes '
                      f'--instr-atstart=no --cache-sim=yes --separate-threads=yes '
                      f'--D1={cache_size},{associativity},64 --I1={cache_size},{associativity},64 {app_cmd}')
  logging.info(f'Valgrind runs {valgrind_cmd}')
  valgrind_proc = sp.Popen(shlex.split(valgrind_cmd), stdout=sp.PIPE, stderr=sp.PIPE, cwd=app_cwd)
  try:
    stdout, stderr = valgrind_proc.communicate(timeout=1)
  except sp.TimeoutExpired:
    pass
  if valgrind_proc.returncode is not None and valgrind_proc.returncode != 0:
    err = stderr.decode()
    logging.fatal(
        f'{args.app} failed to start. Return code: {valgrind_proc.returncode}. Error message: {err}')
    exit(1)
  else:
    logging.info(f'Valgrind for {args.app} started successfully. '
                f'cache size: {cache_size}, associativity: {associativity}')
  time.sleep(20)

  # Load data, if necessary
  if args.load_data:
    logging.info(f'Loading data for {args.app}')
    if 'load_cmd' not in configs:
      logging.fatal(f'Need to provide load commands for {args.app}.')
      exit(1)
    load_cmd = configs['load_cmd']
    load_proc = sp.Popen(shlex.split(load_cmd), stdout=sp.PIPE, stderr=sp.PIPE)
    stdout, stderr = load_proc.communicate()
    if load_proc.returncode is not None and load_proc.returncode != 0:
      err = stderr.decode()
      logging.fatal(
          f'{args.app} failed to load data. '
          f'Return code: {load_proc.returncode}. Error message: {err}')
      exit(1)
    else:
      logging.info(f'{args.app} data loaded successfully')

  time.sleep(1)
  # Start Valgrind profiler
  logging.info(f'Starting Valgrind profiler for {args.app}')
  sp.check_call(f'{callgrind_control_bin} -i on'.split(),
                stdout=sp.PIPE, stderr=sp.PIPE)
  time.sleep(1)
  
  client_cmd = (configs["client_cmd"]
              .replace('<conns>', str(conns))
              .replace('<reqs>', str(qps * duration))
              .replace('<duration>', str(duration))
              .replace('<reqs_per_sec>', str(int(qps)))
              .replace('<reqs_per_sec_per_conn>', str(int(qps / conns))))
  logging.info(f'Starting client for profiling valgrind')
  logging.info(f'Client runs {client_cmd}')
  if 'valgrind_client_cwd' in configs:
    client_proc = sp.Popen(shlex.split(client_cmd), stdout=sp.PIPE, stderr=sp.PIPE, cwd=configs["valgrind_client_cwd"])
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
    with open(f'{client_data_dir}/client_valgrind_{cache_size}_{associativity}.txt', 'w') as f:
      f.write(stdout.decode())
  time.sleep(1)

  sp.check_call(f'{callgrind_control_bin} -i off'.split(), stdout=sp.PIPE, stderr=sp.PIPE)

  # Kill application and valgrind
  logging.info(f'Killing {args.app} with pid {valgrind_proc.pid}')
  os.kill(valgrind_proc.pid, signal.SIGTERM)
  try:
    valgrind_pids = sp.check_output(
        shlex.split(f'pgrep -f callgrind'), stderr=sp.PIPE).decode().strip()
    for pid in valgrind_pids.split():
      try:
        os.kill(int(pid), signal.SIGTERM)
      except ProcessLookupError:
        logging.info(f'Not found process {pid}')
  except:
    pass

  # Parse valgrind_cache output
  valgrind_output = valgrind_proc.stderr.read().decode('utf-8').split('\n')
  with open(os.path.join(valgrind_data_dir, f'valgrind_cache_{cache_size}_{associativity}.txt'), 'w') as f:
    f.write('\n'.join(valgrind_output))
  totol_refs = 0
  rd_refs = 0
  wr_refs = 0
  totol_misses = 0
  rd_misses = 0
  wr_misses = 0
  total_irefs = 0
  total_imisses = 0
  for line in valgrind_output:
    if 'D   refs' in line:
      line = line.replace(',', '').replace('(', '').replace(')', '')
      result = [int(s) for s in line.split() if s.isdigit()]
      totol_refs += result[0]
      rd_refs += result[1]
      wr_refs += result[2]
    elif 'D1  misses' in line:
      line = line.replace(',', '').replace('(', '').replace(')', '')
      result = [int(s) for s in line.split() if s.isdigit()]
      totol_misses += result[0]
      rd_misses += result[1]
      wr_misses += result[2]
    elif 'I   refs' in line:
      line = line.replace(',', '').replace('(', '').replace(')', '')
      result = [int(s) for s in line.split() if s.isdigit()]
      total_irefs += result[0]
    elif 'I1  misses' in line:
      line = line.replace(',', '').replace('(', '').replace(')', '')
      result = [int(s) for s in line.split() if s.isdigit()]
      total_imisses += result[0]

  valgrind_dcache_results[(cache_size, associativity)] = {
      'refs': totol_refs,
      'rd_refs': rd_refs,
      'wr_refs': wr_refs,
      'misses': totol_misses,
      'rd_misses': rd_misses,
      'wr_misses': wr_misses
  }
  valgrind_icache_results[(cache_size, associativity)] = {
      'refs': total_irefs,
      'misses': total_imisses,
  }

# Log valgrind_cache stats
with open(f'{valgrind_data_dir}/valgrind_dcache.yaml', 'w') as f:
  yaml.dump(valgrind_dcache_results, f, indent=2)
with open(f'{valgrind_data_dir}/valgrind_icache.yaml', 'w') as f:
  yaml.dump(valgrind_icache_results, f, indent=2)

# Clean up all valgrind_cache files
sp.call('rm -f callgrind.out.*', shell=True, cwd=app_cwd)