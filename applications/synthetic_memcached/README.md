# Synthetic memcached skeleton

Here we give an example of how to generate the skeleton for synthetic memcached. 

```json
{
  "network_model_characteristics": {
    "accept_dispatch": false,
    "network_dispatch": true,
    "network_epoll": true,
    "nonblocking": false,
    "blocking": false,
    "accept_thread_pool_size": 1,
    "network_thread_pool_size": 4
  }
}
```

Above is the network model characteristics we get from the backbone analysis of the orginal Memcached. Therefore, to generate the synthetic memcached with similar network model, we need to define the macro of network_dispatch as -DNETWORKDISPATCH and network_epoll as -DNETWORKEPOLL in makefile, while the pool size of network threads needs to be specified as command line argument when launching the synthetic application. In this case, the command to compile and launch the synthetic memcached is:

```
make
./syn_memcached -p 9016 (port) -n 4 (number of network threads)
```

This skeleton contains the network-related system calls for the communication, but it may not use the exactly same system calls used by the original application. You can change them or inject new system calls according to the system call characteristics from analysis results.