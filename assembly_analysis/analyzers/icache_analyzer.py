from base_analyzer import BaseAnalyzer
import os
import yaml
import numpy as np

CACHE_SIZES = []
cache_size_init = 64
cache_size_max = 256 * (1 << 20)
while cache_size_init <= cache_size_max:
  CACHE_SIZES.append(cache_size_init)
  cache_size_init *= 2
ASSOCIATIVITIES = [8]

CACHELINE_SIZE = 64
INST_SIZE = 4
class ICacheAnalyzer(BaseAnalyzer):
  def __init__(self, associativity=None, exclude=True, min_size=64, max_size=256*1024*1024, *args, **kwargs):
    super().__init__(*args, **kwargs)
    self.associativity = associativity
    self.exclude = exclude
    self.min_size = min_size
    self.max_size = max_size

  def __calculate_icache_stats(self, icache_stats):
    cache_sizes = sorted(icache_stats.keys())
    access_stats = {}
    for i in range(1, len(cache_sizes)):
      access_stats[cache_sizes[i]] = CACHELINE_SIZE / INST_SIZE * (
          icache_stats[cache_sizes[i]]['hits'] -
          icache_stats[cache_sizes[i - 1]]['hits'])
    access_stats[cache_sizes[0]] = max(0, icache_stats[cache_sizes[0]]['refs'] - sum(list(access_stats.values())))
    s = sum(max(0, v) for _, v in access_stats.items())
    access_stats = {k: max(0, v / s) for k, v in access_stats.items()}
    return access_stats

  def __run_analysis_from_valgrind(self):
    valgrind_file_path = os.path.join(self.input_path, f'{self.app}', 'valgrind', 'valgrind_icache.yaml')
    skeleton_file_path = os.path.join(self.input_path, f'{self.skeleton}', 'valgrind', 'valgrind_icache.yaml')
    with open(valgrind_file_path, 'r') as f:
      self.valgrind_data = yaml.load(f, Loader=yaml.FullLoader)
    with open(skeleton_file_path, 'r') as f:
      self.skeleton_data = yaml.load(f, Loader=yaml.FullLoader)
    ret = {}

    app_refs = int(np.mean([self.valgrind_data[k]['refs'] for k in self.valgrind_data]))
    skeleton_refs = int(np.mean([self.skeleton_data[k]['refs'] for k in self.skeleton_data]))

    if self.associativity:
      for key, value in self.valgrind_data.items():
        if self.exclude:
          ret[key[0]] = {
            'hits': app_refs - skeleton_refs - (value['misses'] - self.skeleton_data[key]['misses']),
            'misses': value['misses'] - self.skeleton_data[key]['misses'],
            'refs': app_refs - skeleton_refs,
          }
        else:
          ret[key[0]] = {
            'hits': app_refs - value['misses'],
            'misses': value['misses'],
            'refs': app_refs,
          }
    else:
      for key, value in self.valgrind_data.items():
        if self.exclude:
          ret[key] = {
              'hits': app_refs - skeleton_refs - (value['misses'] - self.skeleton_data[key]['misses']),
              'misses': value['misses'] - self.skeleton_data[key]['misses'],
              'refs': app_refs - skeleton_refs,
            }
        else:
          ret[key] = {
              'hits': app_refs - value['misses'],
              'misses': value['misses'],
              'refs': app_refs,
            }
    return self.__calculate_icache_stats(ret)

  def run_analysis(self):
    tmp_icache_stats =  self.__run_analysis_from_valgrind()
    icache_stats = {}
    icache_stats[self.max_size] = 0
    icache_stats[self.min_size] = 0

    for k, v in tmp_icache_stats.items():
      if k <= self.min_size:
        icache_stats[self.min_size] += v
      elif k >= self.max_size:
        icache_stats[self.max_size] += v
      else:
        icache_stats[k] = v

    s = sum(icache_stats.values())
    for k in icache_stats:
      icache_stats[k] /= s
    
    icache_stats = {k: icache_stats[k] for k in sorted(icache_stats.keys())}
    return icache_stats