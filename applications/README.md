# Applications

Here we list some exemplary commands to launch, setup and load the application:

## Memcached 

Launch the application:
```
/applications/memcached-1.6.9/build/memcached -p 11212 -t 4
```

Load it with 10K items, each with a 30B key and a 4KB value:
```
/client/mutated/client/load_memcache 0.0.0.0:11212
```

Send user requests:
```
/client/mutated/client/mutated_memcache 0.0.0.0:11212 -n <conns> -w 0 -c 0 -s <duration> <reqs_per_sec>
```

## Synthetic Memcached 

Launch the application:
```
/applications/synthetic_memcached_test/syn_memcached -p 9016 -n 4
```

Send user requests:
```
/client/mutated/client/mutated_synthetic 0.0.0.0:9016 -p 54 -n <conns> -w 0 -c 0 -s <duration> 1000 <reqs_per_sec>
```