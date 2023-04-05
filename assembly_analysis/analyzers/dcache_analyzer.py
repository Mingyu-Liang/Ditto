from base_analyzer import BaseAnalyzer
import os
import yaml
import subprocess as sp
import re
import numpy as np

CACHE_SIZES = []
cache_size_init = 64
cache_size_max = 256 * (1 << 20)
while cache_size_init <= cache_size_max:
  CACHE_SIZES.append(cache_size_init)
  cache_size_init *= 2
ASSOCIATIVITIES = [8]

class DCacheAnalyzer(BaseAnalyzer):
  def __init__(self, associativity=None, exclude=True, min_size=64, max_size=256*1024*1024, source='valgrind', *args, **kwargs):
    super().__init__(*args, **kwargs)
    self.associativity = associativity
    self.exclude = exclude
    self.source = source
    self.min_size = min_size
    self.max_size = max_size

  def __calculate_dcache_stats(self, dcache_stats):
    cache_sizes = sorted(dcache_stats.keys())
    access_stats = {}
    for i in range(len(cache_sizes)):
      if i == 0:
        access_stats[cache_sizes[0]] = (
            dcache_stats[cache_sizes[i]]['refs'] -
            dcache_stats[cache_sizes[i]]['misses'])
      elif i < len(cache_sizes) - 1:
        access_stats[cache_sizes[i]] = (
            dcache_stats[cache_sizes[i - 1]]['misses'] -
            dcache_stats[cache_sizes[i]]['misses'])
      else:
        access_stats[cache_sizes[i]] = (
            dcache_stats[cache_sizes[i - 1]]['misses'])
    s = sum(max(0, v) for _, v in access_stats.items())
    access_stats = {k: max(0, v / s) for k, v in access_stats.items()}
    return access_stats

  def __run_analysis_from_valgrind(self):
    valgrind_file_path = os.path.join(self.input_path, f'{self.app}', 'valgrind', 'valgrind_dcache.yaml')
    skeleton_file_path = os.path.join(self.input_path, f'{self.skeleton}', 'valgrind', 'valgrind_dcache.yaml')
    with open(valgrind_file_path, 'r') as f:
      self.valgrind_data = yaml.load(f, Loader=yaml.FullLoader)
    with open(skeleton_file_path, 'r') as f:
      self.skeleton_data = yaml.load(f, Loader=yaml.FullLoader)
    ret = {}

    app_refs = int(np.mean([self.valgrind_data[k]['refs'] for k in self.valgrind_data]))
    app_rd_refs = int(np.mean([self.valgrind_data[k]['rd_refs'] for k in self.valgrind_data]))
    app_wr_refs = int(np.mean([self.valgrind_data[k]['wr_refs'] for k in self.valgrind_data]))
    skeleton_refs = int(np.mean([self.skeleton_data[k]['refs'] for k in self.skeleton_data]))
    skeleton_rd_refs = int(np.mean([self.skeleton_data[k]['rd_refs'] for k in self.skeleton_data]))
    skeleton_wr_refs = int(np.mean([self.skeleton_data[k]['wr_refs'] for k in self.skeleton_data]))

    if self.associativity:
      for key, value in self.valgrind_data.items():
        if self.exclude:
          ret[key[0]] = {
            'misses': value['misses'] - self.skeleton_data[key]['misses'],
            'rd_misses': value['rd_misses'] - self.skeleton_data[key]['rd_misses'],
            'rd_refs': app_rd_refs - skeleton_rd_refs,
            'refs': app_refs - skeleton_refs,
            'wr_misses': value['wr_misses'] - self.skeleton_data[key]['wr_misses'],
            'wr_refs': app_wr_refs - skeleton_wr_refs,
          }
        else:
          ret[key[0]] = {
            'misses': value['misses'],
            'rd_misses': value['rd_misses'],
            'rd_refs': app_rd_refs,
            'refs': app_refs,
            'wr_misses': value['wr_misses'],
            'wr_refs': app_wr_refs,
          }
    else:
      for key, value in self.valgrind_data.items():
        if self.exclude:
          ret[key] = {
              'misses': value['misses'] - self.skeleton_data[key]['misses'],
              'rd_misses': value['rd_misses'] - self.skeleton_data[key]['rd_misses'],
              'rd_refs': app_rd_refs - skeleton_rd_refs,
              'refs': app_refs - skeleton_refs,
              'wr_misses': value['wr_misses'] - self.skeleton_data[key]['wr_misses'],
              'wr_refs': app_wr_refs - skeleton_wr_refs,
            }
        else:
          ret[key] = {
              'misses': value['misses'],
              'rd_misses': value['rd_misses'],
              'rd_refs': app_rd_refs,
              'refs': app_refs,
              'wr_misses': value['wr_misses'],
              'wr_refs': app_wr_refs,
            }
    return self.__calculate_dcache_stats(ret) 

  def __parse_size(self, size):
    if re.match(r'^\d+$', size):
      return int(size)
    elif re.match(r'^\d+K$', size):
      return int(size[:-1]) * 1024
    elif re.match(r'^\d+M$', size):
      return int(size[:-1]) * 1024 * 1024
    elif re.match(r'^\d+G$', size):
      return int(size[:-1]) * 1024 * 1024 * 1024
    else:
      raise ValueError(f'Invalid size: {size}')

  def __parse_perf_file(self, file, metrics):
    perf_results = {}
    with open(file, 'r') as f:
      for line in f:
        for metric in metrics:
          if re.match(rf'^\s+([\d,]+)\s+{metric}\s+.*$', line):
            perf_results[metric] = int(line.split()[0].replace(',', ''))
    return perf_results

  def __run_analysis_from_perf(self):
    app_perf_l1d_path = os.path.join(self.input_path, f'{self.app}', 'perf', 'perf_l1d-user.txt')
    skeleton_perf_l1d_path = os.path.join(self.input_path, f'{self.skeleton}', 'perf', 'perf_l1d-user.txt')
    app_perf_l2_path = os.path.join(self.input_path, f'{self.app}', 'perf', 'perf_l2-user.txt')
    skeleton_perf_l2_path = os.path.join(self.input_path, f'{self.skeleton}', 'perf', 'perf_l2-user.txt')
    app_perf_llc_load_path = os.path.join(self.input_path, f'{self.app}', 'perf', 'perf_llc-load-user.txt')
    skeleton_perf_llc_load_path = os.path.join(self.input_path, f'{self.skeleton}', 'perf', 'perf_llc-load-user.txt')
    app_perf_llc_store_path = os.path.join(self.input_path, f'{self.app}', 'perf', 'perf_llc-store-user.txt')
    skeleton_perf_llc_store_path = os.path.join(self.input_path, f'{self.skeleton}', 'perf', 'perf_llc-store-user.txt')
    p = sp.Popen("cat /sys/devices/system/cpu/cpu0/cache/index1/size", shell=True, stdout=sp.PIPE)
    l1_size = self.__parse_size(p.stdout.read().decode('utf-8').strip())
    p = sp.Popen("cat /sys/devices/system/cpu/cpu0/cache/index2/size", shell=True, stdout=sp.PIPE)
    l2_size = self.__parse_size(p.stdout.read().decode('utf-8').strip())
    p = sp.Popen("cat /sys/devices/system/cpu/cpu0/cache/index3/size", shell=True, stdout=sp.PIPE)
    llc_size = self.__parse_size(p.stdout.read().decode('utf-8').strip())

    # TODO: Currently perf only suppert loads for L1D
    # Assume load miss rate is the same as store miss rate
    app_l1_perf_metrics = self.__parse_perf_file(
        app_perf_l1d_path, ['L1-dcache-loads', 'L1-dcache-stores', 'L1-dcache-load-misses'])
    skeleton_l1_perf_metrics = self.__parse_perf_file(
        skeleton_perf_l1d_path, ['L1-dcache-loads', 'L1-dcache-stores', 'L1-dcache-load-misses'])
    app_l2_perf_metrics = self.__parse_perf_file(
        app_perf_l2_path, ['l2_rqsts.references:u', 'l2_rqsts.miss:u', 'l2_rqsts.code_rd_hit:u', 'l2_rqsts.code_rd_miss:u'])
    skeleton_l2_perf_metrics = self.__parse_perf_file(
        skeleton_perf_l2_path, ['l2_rqsts.references:u', 'l2_rqsts.miss:u', 'l2_rqsts.code_rd_hit:u', 'l2_rqsts.code_rd_miss:u'])
    app_llc_load_perf_metrics = self.__parse_perf_file(
        app_perf_llc_load_path, ['LLC-loads', 'LLC-load-misses'])
    skeleton_llc_load_perf_metrics = self.__parse_perf_file(
        skeleton_perf_llc_load_path, ['LLC-loads', 'LLC-load-misses'])
    app_llc_store_perf_metrics = self.__parse_perf_file(
        app_perf_llc_store_path, ['LLC-stores', 'LLC-store-misses'])
    skeleton_llc_store_perf_metrics = self.__parse_perf_file(
        skeleton_perf_llc_store_path, ['LLC-stores', 'LLC-store-misses'])

    if self.exclude:
      l1_loads = app_l1_perf_metrics['L1-dcache-loads'] - skeleton_l1_perf_metrics['L1-dcache-loads']
      l1_stores = app_l1_perf_metrics['L1-dcache-stores'] - skeleton_l1_perf_metrics['L1-dcache-stores']
      l1_refs = l1_loads + l1_stores
      l1_load_misses = app_l1_perf_metrics['L1-dcache-load-misses'] - skeleton_l1_perf_metrics['L1-dcache-load-misses']
      l2_code_loads = app_l2_perf_metrics['l2_rqsts.code_rd_hit:u'] + app_l2_perf_metrics['l2_rqsts.code_rd_miss:u'] - skeleton_l2_perf_metrics['l2_rqsts.code_rd_hit:u'] - skeleton_l2_perf_metrics['l2_rqsts.code_rd_miss:u']
      l2_code_load_misses = app_l2_perf_metrics['l2_rqsts.code_rd_miss:u'] - skeleton_l2_perf_metrics['l2_rqsts.code_rd_miss:u']
      l2_refs = app_l2_perf_metrics['l2_rqsts.references:u'] - skeleton_l2_perf_metrics['l2_rqsts.references:u']
      l2_misses = app_l2_perf_metrics['l2_rqsts.miss:u'] - skeleton_l2_perf_metrics['l2_rqsts.miss:u']
      l2_data_refs = l2_refs - l2_code_loads
      l2_data_misses = l2_misses - l2_code_load_misses
      l1_store_misses = l2_data_refs - l1_load_misses
      l3_misses = app_llc_load_perf_metrics['LLC-load-misses'] + app_llc_store_perf_metrics['LLC-store-misses'] - skeleton_llc_load_perf_metrics['LLC-load-misses'] - skeleton_llc_store_perf_metrics['LLC-store-misses']
      l3_data_misses = l3_misses * l2_data_misses / l2_misses
      mem_stats = {
        l1_size: {
          'misses': l1_load_misses + l1_store_misses,
          'refs': l1_refs
        }, 
        l2_size: {
          'misses': l2_data_misses,
          'refs': l1_refs
        },
        llc_size: {
          'misses': l3_misses,
          'refs': l1_refs
        },
      }
    else:
      l1_loads = app_l1_perf_metrics['L1-dcache-loads']
      l1_stores = app_l1_perf_metrics['L1-dcache-stores']
      l1_refs = l1_loads + l1_stores
      l1_load_misses = app_l1_perf_metrics['L1-dcache-load-misses']
      l2_code_loads = app_l2_perf_metrics['l2_rqsts.code_rd_hit:u'] + app_l2_perf_metrics['l2_rqsts.code_rd_miss:u']
      l2_code_load_misses = app_l2_perf_metrics['l2_rqsts.code_rd_miss:u']
      l2_refs = app_l2_perf_metrics['l2_rqsts.references:u']
      l2_misses = app_l2_perf_metrics['l2_rqsts.miss:u']
      l2_data_refs = l2_refs - l2_code_loads
      l2_data_misses = l2_misses - l2_code_load_misses
      l1_store_misses = l2_data_misses - l1_load_misses
      l3_misses = app_llc_load_perf_metrics['LLC-load-misses'] + app_llc_store_perf_metrics['LLC-store-misses']
      l3_data_misses = l3_misses * l2_data_misses / l2_misses
      mem_stats = {
        l1_size: {
          'misses': l1_load_misses + l1_store_misses,
          'refs': l1_refs
        }, 
        l2_size: {
          'misses': l2_data_misses,
          'refs': l1_refs
        },
        llc_size: {
          'misses': l3_misses,
          'refs': l1_refs
        },
      }
    return self.__calculate_dcache_stats(mem_stats)

  def __hybrid_rebalance(self, valgrind_mem_stats, perf_mem_stats):
    mem_ststs = {}
    perf_sizes = [0] + list(perf_mem_stats.keys())
    for i in range(1, len(perf_sizes)):
      weights = 0
      for valgrind_size in valgrind_mem_stats.keys():
        if perf_sizes[i - 1] < valgrind_size <= perf_sizes[i]:
          weights += valgrind_mem_stats[valgrind_size]
      for valgrind_size in valgrind_mem_stats.keys():
        if perf_sizes[i - 1] < valgrind_size <= perf_sizes[i]:
          mem_ststs[valgrind_size] = valgrind_mem_stats[valgrind_size] / weights * perf_mem_stats[perf_sizes[i]]
    return mem_ststs

  def run_analysis(self):
    if self.source == 'perf':
      tmp_dcache_stats = self.__run_analysis_from_perf()
    elif self.source == 'valgrind':
      tmp_dcache_stats =  self.__run_analysis_from_valgrind()
    elif self.source == 'hybrid':
      perf_mem_stats = self.__run_analysis_from_perf()
      valgrind_mem_stats = self.__run_analysis_from_valgrind()
      tmp_dcache_stats = self.__hybrid_rebalance(valgrind_mem_stats, perf_mem_stats)
    else:
      raise Exception('Unknown source: ' + self.source)

    dcache_stats = {}
    dcache_stats[self.max_size] = 0
    dcache_stats[self.min_size] = 0

    for k, v in tmp_dcache_stats.items():
      if k <= self.min_size:
        dcache_stats[self.min_size] += v
      elif k >= self.max_size:
        dcache_stats[self.max_size] += v
      else:
        dcache_stats[k] = v

    s = sum(dcache_stats.values())
    for k in dcache_stats:
      dcache_stats[k] /= s

    dcache_stats = {k: dcache_stats[k] for k in sorted(dcache_stats.keys())}
    
    return dcache_stats