# Ditto-dev

## Pre-requirements

* Python-3.7.6
* SystemTap-4.4
* Linux Perf-5.4.166
* Valgrind-3.19.0

  We make a minor modification to enable valgrind emulation with cache size equal to cache line size ([cachegrind/cg_arch.c](./valgrind/cachegrind/cg_arch.c)). The modified source code is provided and you may recompile it on your platform.

* Intel SDE-8.63.0

Tools are tested on Ubuntu 20.04.4 LTS (GNU/Linux 5.4.0-100-generic x86_64 with debugging symbols). You may need to install different versions of the tools if using different Linux distributions and kernel versions.

## Usage

1. The first step is to analyze the network and thread model of the target application. Follow the instructions in the [README.md](./backbone_analysis/README.md) of backbone analysis.

2. Generate the backbone of the synthetic application following the instructions in the [README.md](./network_skeleton//README.md) based on the analysis results of step 1. An example of the generation of synthetic Memcached skeleton is provided in [synthetic_memcached_skeleon](./synthetic_memcached_skeleton/).

3. Next, we run Intel SDE and Valgrind to profile the platform-independent features of the orignal application. Note that we also need to do the similar profiling on the skeleton of the synthetic application to take into account the existing codes. We then generate the synthetic assembly codes as the application body in the request handler. More details can be found at [README.md](./assembly_analysis/README.md).

4. Finally, we run the synthetic application and collect the performance characteristics with Perf, and fine tune the parameters of the generator to calibrate the output of previous steps, due to inaccuracies introduced by profiling.