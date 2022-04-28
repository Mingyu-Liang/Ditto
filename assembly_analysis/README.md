# Assembly analysis

1. First, we need Intel SDE to collect the dynamic control flow graph (dcfg) and instruction mix (imix) of the original application. Make sure the application has been launched and loaded before running the profiling scripts. To run SDE, you need to specify the settings of your client, which includes the number of connections, qps and duration. Ideally you want the setup to be as close to the real-world scenario as possible, but given the overhead of SDE, you need to make sure that the application is not saturated, which means that all outgoing requests are receiving responses. An example of the command to run SDE is:

    ```
    python run_sde.py -a <app_name> -c <connections> -q <qps> -d <duration> -p <main_process_pid>
    ```

    More details about the command arguments can be found in [run_sde.py](./run_sde.py).

2. Next, we profile the dcache and icache hits of the original application with different cache sizes using Valgrind. Theoretically we need to run valgrind to simulate the cache size from 64 bytes (cache line size) to the maximum memory size allocated to the target application, increasing by a factor of 2. However, if the simulated cache size is larger than the size of platform's LLC, any cache size above that will all cause the LLC misses. Therefore, you may adjust the upper bound of the simulated cache size to save time according to the LLC size of your test platform. In terms of associativity, currently we assume it as 8 for simplicity and it may be extended in the future if necessary. 

    Similar to SDE profiling, you need to specify the appropriate settings of your client. The only difference is that we need to directly launch the application with Valgrind, so please remember to provide the command in [profiling_config.json](./profiling_config.json) to load the data (if necessary) before profiling. An example of the command to run Valgrind is:

    ```
    python run_valgrind.py -a <app_name> -c <connections> -q <qps> -d <duration> -l
    ```

    More details about the command arguments can be found in [run_valgrind.py](./run_valgrind.py).

3. Then, run the same SDE and Valgrind profiling for the synthetic application skeleton since when generating the assembly code as the application body, we need to consider the existing codes (application skeleton). You can imagine this process as: the statistics of the original application is the target, the statistics of the skeleton part is what we already have, and the subtraction of the two is what we need to add as the body part. 

4. Run the generator script to generate the assembly code. This part is still under construction.