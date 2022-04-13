# Network skeleton

By defining the macros in Makefile, network skeleton can be configured to generate different network models as descriped in backbone_analysis. The macros can be specified based on the previous analysis results from backbone_analysis. 

Available macros and their corresponding pairs in network_model_characteristics from analysis results:

| macros           | pairs in network_model_characteristics |
| ---------------- | -------------------------------------- |
| ACCEPTDISPATCH   | accept_dispatch                        |
| NETWORKDISPATCH  | network_dispatch                       |
| NETWORKEPOLL     | network_epoll                          |
| NONBLOCKING      | nonblocking                            |
| BLOCKING         | blocking                               |

The thread pool size of acceptor threads and network threads (if necessary) can be specified as command line arguments when launching the synthetic application, for ease of adjustment. See *config.cpp* for details.

Note that this network skeleton has included the initialization of memory array in heap for future memory access when injecting assembly codes in the request handler.