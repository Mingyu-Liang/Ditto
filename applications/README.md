# Applications

Here we list some exemplary commands to launch, setup and load the application. Note that before running the application, you may need to recompile it on your platform.

## Memcached 

### Memcached
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

### Synthetic Memcached 

Launch the application:
```
/applications/synthetic_memcached_test/syn_memcached -p 9016 -n 4
```

Send user requests:
```
/client/mutated/client/mutated_synthetic 0.0.0.0:9016 -p 54 -n <conns> -w 0 -c 0 -s <duration> 1000 <reqs_per_sec>
```

## Nginx 

### Nginx
Launch the application:
```
/applications/nginx-1.20.1/build/sbin/nginx -c /applications/nginx-1.20.1/build/conf/nginx.conf
```

Send user requests:
```
/client/tcpkali/build/bin/tcpkali -vvv -em "GET / HTTP/1.1\r\nHost: 0.0.0.0:18081\r\n\r\n" -c <conns> -r <reqs_per_sec_per_conn> -T <duration> --latency-percentiles 50,90,95,99 --latency-marker "HTTP/1.1" 0.0.0.0:18081
```

### Synthetic Nginx 

Launch the application:
```
/applications/synthetic_nginx/syn_nginx -p 9017 -n 1
```

Send user requests:
```
/client/tcpkali/build/bin/tcpkali -vvv -em "GET\n" -c <conns> -r <reqs_per_sec_per_conn> -T <duration> --latency-percentiles 50,90,95,99 --latency-marker "reply" 0.0.0.0:9017
```

## Redis 

### Redis
Launch the application:
```
/applications/redis-6.2.6/src/redis-server /applications/redis-6.2.6/redis.conf
```

Load it with 100K records:
```
python2 /client/ycsb-redis-binding-0.18.0-SNAPSHOT/bin/ycsb load redis -P /applications/workloads/redis_ycsb.txt -threads 1 -target 5000
```

Send user requests:
```
python2 /client/ycsb-redis-binding-0.18.0-SNAPSHOT/bin/ycsb run redis -P /applications/workloads/redis_ycsb.txt -threads <conns> -p operationcount=<reqs> -target <reqs_per_sec>
```

### Synthetic Redis 

Launch the application:
```
/applications/synthetic_redis/syn_redis -p 9018
```

Send user requests:
```
python2 /client/ycsb-syn-redis-binding-0.18.0-SNAPSHOT/bin/ycsb run redis -P /applications/workloads/syn-redis_ycsb.txt -threads <conns> -p operationcount=<reqs> -target <reqs_per_sec>