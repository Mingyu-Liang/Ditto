# Backbone analysis

## Overview

We use SystemTap ([threads.stp](./threads.stp)) to collect information of syscalls and Perf to collect function call stacks of target processes/threads. Applications need to be launched and loaded before running the profiling scripts ([run_profiling.py](./run_profiling.py)) and the pid of main process is required as input. The configuration of client should be specified in [profiling_config.json](./profiling_configs.json).

## Analysis

* Overall ([analyze.py](./analyze.py)): Our backbone analysis consists of the following three parts:

* Thread/process clustering ([analyze_cluster.py](./analyze_cluster.py)). Based on the collected call stack information by Perf, we measure the call stack distance between threads with tree distance (defined in [tree-similarity](./tree-similarity)) and cluster threads using AgglomerativeClustering. 

* Network model ([analyze_network_model.py](./analyze_network_model.py)). Currently we assume a three-stage network processing model: main thread -> acceptor thread -> network thread. Main thread handles the initialization stuff, acceptor thread accepts new connections from clients and finally network thread does network I/O and processes the user requests. Some stages can be processed in the same thread and we use accept_dispatch and network_dispatch in the output to indicate where each of these stages occurs. For example, Redis uses a single-thread model with all stages processed in the same thread, so both accept_dispatch and network_dispatch would be set to be False. As for Memcached, it is the main thread that also accepts new connections and then dispatches them to its worker threads, so accept_dispatch is False and network_dispatch is True. 

  For the acceptor thread, we always assume it uses the epoll-based thread pool model since we can only detect a new connection by getting responses from accept(), by which time it is too late to spawn a new thread (unlike a network thread, where we know in advance that a connection has been established, so we can spawn a thread to handle its I/O, here we have no prior information. The analysis output will contain fields that tell the size of the thread pool.

  For the network thread, there can be three options to handle network I/O: epoll-based multiplexing, blocking and nonblocking. In contrast to the other two models, the non-blocking model needs to periodically call the I/O interfaces to look for new requests, which can waste CPU time at low loads. In both blocking and I/O multiplexing models, threads block on system calls, although epoll-based multiplexing allows monitoring multiple sockets via a single system call (epoll()). For blocking and nonblocking models, we assume it needs to spawn a thread for each new connection to guarantee responsiveness since each thread can only serve one connection and using thread pool can cause starvation if all threads are occupied. Instead, due to the benefits of multiplexing, we assume that a thread pool is maintained for the epoll-based model, otherwise there would be no point in using epoll (if we just generate a new thread for each connection). The analysis result will contain fields to indicate which option was used and what is the size of the thread pool if epoll is used.

  All of our assumptions above are based on the observations of popular applications, and they are also the most common implementations in terms of network I/O handling. There may be exceptions that arise, and our network model can be extended to accommodate these cases.

* Syscall ([analyze_syscall.py](./analyze_syscall.py)). For now, we only consider syscalls invoked by network threads and we will collect the parameter distribution of syscalls in a predefined set, so that we can faithfully reproduce them and their performance characteristics in the synthetic applications. If there are some syscalls that have not been seen before, then the predefined set may need to be extended.

## Steps

1. Launch the application and load the dataset.

2. Specify the proper settings of the client with varying number of connections, qps, and duration in [profiling_config.json](./profiling_configs.json), where an example of Memcached has been provided.

    Run the profiling scripts to collect traces.

    ```
    python run_profiling.py -a app_name (key in profiling_config.json) -p main_process_pid
    ```

3. Run the analysis scripts to analyze the traces. It will output the analysis results in json style, which contains the characteristics of threads, syscall and network model. Network model characteristics can be used to reproduce the synthetic application as input of [network_skeleton](../network_skeleton/). The syscall characteristics can be used as a reference to reproduce the syscall behavior of the target application.

    ```
    python analyze.py -a app_name -p main_process_pid
    ```