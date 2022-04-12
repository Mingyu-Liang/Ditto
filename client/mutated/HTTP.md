# HTTP Benchmark Tool Summary

## Desired features

Basics:
* Multiple connections
* Keep-Alive (HTTP 1.1)
* Requests to run
* Warm-up period

Advanced:
* Pipelined requests
* Multi-part responses
* HTTP/2
* Mixture of new-connections, Keep-Alive
* POST
* HTTPS

Coordinator:
* Increase concurrency slowly

## Testing mistakes

* Ensure configuration of different webservers is equivalent:
  - Are they hitting disk or just memory?
  - Are they serving a static file or dynamic content?
  - Are they loading equivalent functionality? PHP, FastCGI... etc? (mostly if
    looking at memory footprint)
  - Is logging fairly similar?

* Don't (unless trying to) test the network:
  - Ensure fat enough pipes (10GbE+), may need multiple load generating
    machines
  - Can use localhost, ideally dual socket then and pin webserver to one
    socket, load generator to other

* Be careful picking the payload:
  - Probably want a small file if using files, as otherwise largely testing
    kernel
  - Be sure caching is equivalent across webservers, or you are happy testing
    the difference (some may rely on kernel FS caching, others doing their own,
    some may only cache data, while others cache metadata too...)
  - May want to use an ''embedded resource'', e.g., a transparent gif provided
    in-memory by the webserver

* Probably want to use `HTTP-KeepAlive`:
  - New connections very slow, more of test on webserver when using persistent
    connections

* TCP stack warm-up:
  - Set `TCP_NODELAY`
  - TCP-SlowStart needs to increase the congestion window, starting from 1, to
    get to it's peak transmission rate, need to allow time to warmup
  - Two things affect initial transmission rate: client advertised receive side
	window (`initrwnd`), and server side inital congestion control window
    (`initcwnd`) - initial transfer size is lower of two

* Be pedantic about your testing configuration:
  - Exact CPU, RAM, NIC, switch, OS, drivers, compiler... etc
  - Use `cpuset` or other tools for CPU pinning
  - Avoid frequency scaling and other sources of interference
  - Avoid IPTables... etc
  - Increase number of allowed file descriptors
  - Increase ports allowed to whole ephemeral range [1024, 65535]

## /etc/sysctl.conf

    # "Performance Scalability of a Multi-Core Web Server", Nov 2007
    # Bryan Veal and Annie Foong, Intel Corporation, Page 4/10
	fs.file-max = 5000000
	net.core.netdev_max_backlog = 400000
	net.core.optmem_max = 10000000
	net.core.rmem_default = 10000000
	net.core.rmem_max = 10000000
	net.core.somaxconn = 100000
	net.core.wmem_default = 10000000
	net.core.wmem_max = 10000000
	net.ipv4.conf.all.rp_filter = 1
	net.ipv4.conf.default.rp_filter = 1
	net.ipv4.ip_local_port_range = 1024 65535
	net.ipv4.tcp_congestion_control = bic
	net.ipv4.tcp_ecn = 0
	net.ipv4.tcp_max_syn_backlog = 12000
	net.ipv4.tcp_max_tw_buckets = 2000000
	net.ipv4.tcp_mem = 30000000 30000000 30000000
	net.ipv4.tcp_rmem = 30000000 30000000 30000000
	net.ipv4.tcp_sack = 1
	net.ipv4.tcp_syncookies = 0
	net.ipv4.tcp_timestamps = 1
	net.ipv4.tcp_wmem = 30000000 30000000 30000000    

    # optionally, avoid TIME_WAIT states on localhost no-HTTP Keep-Alive tests:
    #    "error: connect() failed: Cannot assign requested address (99)"
    # On Linux, the 2MSL time is hardcoded to 60 seconds in /include/net/tcp.h:
    # #define TCP_TIMEWAIT_LEN (60*HZ)
    # The option below is safe to use:
	net.ipv4.tcp_tw_reuse = 1

    # The option below lets you reduce TIME_WAITs further
    # but this option is for benchmarks, NOT for production (NAT issues)
	net.ipv4.tcp_tw_recycle = 1

    # don't decrease window size after idle
    net.ipv4.tcp_slow_start_after_idle = 0

## HTTP Persistent Connections

* HTTP 1.0: Need `Connection: keep-alive` header
* HTTP 1.1: Considered persistent by default
* HTTP 2.0: Considered persistent by default

## Apache Bench (ab)

One of the oldest and most widely used. Features include:

* HTTP/HTTPS
* Setting number of requests to perform
* Setting number of connections to use
* Setting max time to run for (finishes when time or requests run out)
* Using HTTP Keep-Alive
* Setting TCP send/receive buffers
* PUT/POST data
* Setting various HTTP headers
* HTTP Basic Authentication
* Timeouts for requests
* Connections created on first request

Output given is:

* Time taken
* Completed/failed requests
* Request per second
* Bytes sent & received, HTTP vs body/payload
* Latency distribution of requests (ms granularity)
* Output all request service times to a file

Apache Bench has the following major limitations:

* Closed loop - 1 outstanding request
* Single threaded
* Blocking writes - may miss read opportunities (only applies when > 1
  connection)
* No request scheduling control, just keeps 1 outstanding request at all times

Design is roughly as follows:

* Apache licence
* C, uses Apache Portable Runtime - pool allocator, event & socket abstraction
* Single threaded
* One global static tx buffer for requests
* One global static rx buffer for responses - responses aren't parsed, we just
  expect a known-size response
* Non-blocking socket IO using epoll
* Reading done in non-blocking fashion
* Writing done in a blocking fashion - just keeps calling `write` system call
  until all of data is exhausted

## Weighttp

For Lighttpd project, features include:

* HTTP only
* Setting number of requests to perform
* Setting number of connections to use
* Multi-threaded
* Using HTTP Keep-Alive
* Setting various HTTP headers
* Connections created on first request

Output given is:

* Time taken
* Completed/failed requests
* Requests per second
* Bytes sent & received, HTTP vs body/payload
* Response status code breakdown

Weighttp has the following major limitations:

* Closed loop - 1 outstanding request
* No request scheduling control, just keeps 1 outstanding request at all times

Design is roughly as follows:

* MIT licence
* Autotools build
* C, uses libev and pthreads
* Multi-threaded - divides number of connections among worker threads, each
  worker exclusively manages N connections
* Non-blocking socket IO using libev (epoll)
* Single, heap-allocated buffer shared by all connections for requests
* Per-connection statically size, heap-allocated buffer for responses and
  parsing results - 2xx, 3xx, 4xx...?

## Siege

Features include:

* HTTP/HTTPS
* HTTP basic authentication
* Cookie support
* Header support
* GET/POST support
* Can generate load against one or more URLs

Output given is:

* Unknown

Following major limitations:

* Closed loop - 1 outstanding request
* No request scheduling control, just keeps 1 outstanding request at all times
* Doesn't support KeepAlive
* Only supports 1 connection per thread

Design is roughly as follows:

* GPLv3 licence
* C, uses openssl and pthreads
* Autotools build
* Blocking IO
* Allocates new buffer for each request
* Memcpy for each response read, parses responses
* Printf for request generation

## Wrk

Features include:

* HTTP/HTTPS
* Setting duration of test
* Setting number of connections to use
* Setting number of threads to use
* Using HTTP Keep-Alive
* PUT/POST data
* Setting various HTTP headers
* HTTP Basic Authentication
* Timeouts for requests
* Connections all created at startup before any requests sent
* Lua for scripting requests, and parsing responses

Output given is:

* Time taken
* Completed requests
* Request per second
* Bytes sent & received
* Latency distribution of requests (.XX ms granularity)

Following major limitations:

* Closed loop - 1 outstanding request
* No request scheduling control, just keeps 1 outstanding request at all times

Design is roughly as follows:

* Apache licence
* Makefile build system
* C, luajit, openssl and pthreads
* Own select/epoll abstraction (`ae` event loop from Redis)
* Uses NGINX derived `http_parser.c`
* Tiny Mersenne Twister PRNG
* All connections established on startup
* Initial calibration period (0.5s) for histograms
* Uses LuaJIT for scripting support
* Lua can be run just once at only startup to generate a fixed request
* In general, only pay for the dynamic cost of Lua when needed - request
  generation, result parsing... etc
* Histogram stats recording
* No allocation (unless dynamic / Lua) on hot-path

## Wrk2

Wrk differences:

* Replaces wrk's historgrams with HdrHistorgrams for better fidelity
* Enables setting a request/s target
* Controls hitting the target with timer events
* Extends initial calibration to 10s

Avoiding 'co-ordinated omission' (i.e., closed-loop):

1. Send request regardless of response received (i.e., pipelining /
   asynchronous):
   - Claims this is only effective with non-blocking protocols or
     single-request-per-connection workloads.
2. Measure request start time from when it was meant to be transmitted, not
   from when it was transmitted (mutated, client-side queuing):
   - Still only allow 1 outstanding request
   - Once we fall behind, we don't just send as fast as possible to catchup, we
     just try sending at twice the requested throughput until we catchup.

Mutated does something similar to (2), or, sort of a cross of (1) and (2). We
allow more than one outstanding request on the wire, but we start measuring the
start time from when it should have been sent. We just keep a huge client-side
buffer that we put requests onto when they should be transmitted, and try to
drain that buffer to the network as quickly as we can.

Perhaps some ideas from (2) of thinking of 'start-time' as the clear component
can be used to optimize memory usage (similar to my 'lazy request construction'
idea).

## Pronk

Features include:

* HTTP/HTTPS
* Setting number of connections to use
* Setting number of threads to use (sort of, through GHC RTS)
* Setting number of requests to send
* Setting max request/s rate to hit
* Using HTTP Keep-Alive
* GET/POST support
* PUT/POST data
* Timeouts for requests
* Saving raw results to a file
* Connections all created at startup before any requests sent

Output given is:

Following major limitations:

* Haskell - performance, lots of allocation, GC
* Can set max request rate, but otherwise is closed-loop
* Connection closed every response - no KeepAlive

Design is roughly as follows:

* Create a new Haskell thread per connection
* Run a fixed loop per thread, using HTTP-conduit
* Memory allocation for responses
* Request allocated once
* Rely on GHC two-level scheduler for OS threads

## h2load

Features include:

* HTTP/HTTPS/HTTP2
* Setting number of connections to use
* Setting number of threads to use
* Number of requests to perform in total
* Support hitting multiple URLs
* Support setting headers
* Support GET/POST
* Support POST data
* Support creating new connections at a fixed rate
* Setting a connection life-span
* Connection inactive timeout
* Support setting a timing (and URI) schedule from a file

Output given is:

* Same as `weighttp` actually, but also includes some basic latency
  measurements: min, max, mean, stdev

Following major limitations:

* Closed loop - 1 outstanding request
* No request scheduling control, just keeps 1 outstanding request at all times

Design is roughly as follows:

* Creates N threads - suggests one per core
* Splits number of connections evenly among all threads
* Uses non-blocking-IO with libev
* Uses own parser for HTTP/2 and nodejs HTTP1 parser
* Appears to avoid allocation on hot path

## ab.c

Runs multiple iterations of either `ab`, `weighttp` or `httperf` to see how
performance changes with different concurrency (connection) numbers. Also
measures CPU load and RAM usage during the test and monitors the process
(nginx, apache... etc) being tested. It does this both to get CPU/RAM usage
just for that process and its workers and to monitor if any crashes occur
during testing.

Written in C, no build system.

## bombard

Similar to `ab.c`, but written in Perl. Only handles doing multiple experiment
runs at differing concurrency, doesn't measure CPU/RAM usage during as `ab.c`
does. Only works with `siege`.

