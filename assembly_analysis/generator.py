import pickle
from assembly_generator import AssemblyGenerator

"""
Args of AssemblyGenerator:
  app: the name of the original application
  skeleton: the name of the skeleton of synthetic application
  input_path: the path of the input file, e.g., the input file should be provided at {input_path}/{app/skeleton}/
  app_tids: indices of the original application's threads that we care about (e.g., network threads) in SDE results
  skeleton_tids: indices of the synthetic skeleton's threads that we care about (e.g., network threads) in SDE results
  sde_total_reqs: the total number of requests in the profiled SDE results
  min_dcache_size: the minimum size of the working set of the data accesses in the generated assembly
  max_dcache_size: the maximum size of the working set of the data accesses in the generated assembly
  min_icache_size: the minimum size of the working set of the instruction accesses in the generated assembly
  max_icache_size: the maximum size of the working set of the instruction accesses in the generated assembly
  debug: whether to add debug information to the generated assembly

Above are arguments required to generate the assembly code. Below are some common parameters you can change 
according to the Perf stats during the fine tuning. You may find more in assembly_generator.py.

  num_block_replicas: the number of replicas of each block (with different sizes) in the generated assembly
  page_multiplier: page shift size for TLB miss
  pointer_chase_rate: the ratio of pointer chasing to all data accesses
  num_dynamic_insts: the number of dynamic instructions in the generated assembly
  num_reqs_per_iteration: the number of requests needed to access all the working sets once
  hard_branch_rate: the ratio of branches that are hard to be predicted to all branches
  dcache_stats: the distribution of the working set size of data accesses in the generated assembly
  icache_stats: the distribution of the working set size of instruction accesses in the generated assembly
  imix_hist: the distribution of the instruction mix in the generated assembly
"""

# ----------------------------------------------------------------------------
# Memcached
# ----------------------------------------------------------------------------

try:
  with open(f'memcached_generator.pkl', 'rb') as f:
    generator = pickle.load(f)
except:
  # Generator not found. Run the generator first.
  generator = AssemblyGenerator(
    app='memcached', skeleton='syn_memcached_skeleton', input_path='./logs',
    app_tids=[2,3,4,5], skeleton_tids=[1,2,3,4], sde_total_reqs=10000*30,
    min_dcache_size=64, max_dcache_size=256*1024*1024,
    min_icache_size=64, max_icache_size=64*1024, debug=False
  )
  with open('memcached_generator.pkl', 'wb') as f:
    pickle.dump(generator, f)

# Parameters adjusted for memcached during the fine tuning
generator.num_dynamic_insts=3500
generator.icache_stats = {
  8192: 0.5,
  16384: 0.5,
}
generator.num_block_replicas = {k: 10 for k in generator.icache_stats.keys()}
generator.dcache_stats[128] -= 0.1
generator.dcache_stats[32*1024] += 0.1
generator.pointer_chase_rate=0.8
generator.page_multiplier=32
generator.hard_branch_rate=1

# Generate the assembly code
asm = generator.generate_asm()
print(asm)