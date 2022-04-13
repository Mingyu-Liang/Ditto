# Network skeleton

By defining the macros in makefile, network skeleton can be configured to generate different network models as descriped in backbone_analysis. The macros can be specified based on the previous analysis results from [backbone_analysis](../backbone_analysis/). 

Available macros and their corresponding pairs in network_model_characteristics from analysis results:

| macros           | pairs in network_model_characteristics |
| ---------------- | -------------------------------------- |
| ACCEPTDISPATCH   | accept_dispatch                        |
| NETWORKDISPATCH  | network_dispatch                       |
| NETWORKEPOLL     | network_epoll                          |
| NONBLOCKING      | nonblocking                            |
| BLOCKING         | blocking                               |

The thread pool size of acceptor threads and network threads (if necessary) can be specified as command line arguments when launching the synthetic application, for ease of adjustment. See [config.cpp](./config.cpp) for details.

This skeleton contains the network-related system calls for the communication, but it may not use the exactly same system calls used by the original application. You can change them or inject new system calls according to the system call characteristics from analysis results.

Note that this network skeleton has included the initialization of memory array in heap for future memory access when injecting assembly codes in the request handler.