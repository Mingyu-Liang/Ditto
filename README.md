# Ditto-dev

## Pre-requirements

* Python-3.7.6
* SystemTap-4.4
* Linux Perf-5.4.166
* Valgrind-3.19.0: We make a minor modification to enable valgrind emulation with cache size equal to cache line size. The modified source code is provided and you may recompile it on your platform.
* Intel SDE-8.63.0

Tools are tested on Ubuntu 20.04.4 LTS (GNU/Linux 5.4.0-100-generic x86_64 with debugging symbols). You may need to install different versions of the tools if using different Linux distributions and kernel versions.

## Experiments

### Backbone Analysis

Analyze the network and thread model of the target applications. Follow the instructions under backbone_analysis.

Generate the backbone of synthetic application with network_skeleton. Follow the instructions under network_skeleton.

### Run SDE and Valgrind

### Generate the synthetic application body with assembly codes.

### Collect the perf results and fine tune.

