# Mutated

Mutated a high-performance and very accurate load-generator for stressing
servers and measuring their latency behaviour under load.

It tries to avoid mistakes made in previous load-generators such as
[mutilate](https://github.com/leverich/mutilate), to which mutated owes much of
its inspiration and learning to.

## Licensing

Mutated is BSD-licensed.

## Supported protocols

Currently we support our own synthetic protocol, and memcache. Adding new
protocols should be fairly easy at this point.

To evaluate against the synthetic protocol, you should grab our collection of
servers supporting it from [ghola](http://github.com/scslab/ghola).

## Using

We split each supported protocol into its own binary for now so as to keep the
command line interface focused and simple. Below is the synthetic protocol:

``` sh
Usage: ./client/mutated_synthetic [options] <ip:port> <exp. service us> <req/sec>

Options:
  -h    : help
  -r    : print raw samples
  -e    : use Shinjuku's epoll_spin() system call
  -w INT: warm-up seconds (default: 5s)
  -c INT: cool-down seconds (default: 5s)
  -s INT: measurement sample count (default: 10s worth)
  -l STR: label for machine-readable output (-r)
  -m OPT: connection mode (default: round_robin)
  -d OPT: the service time distribution (default: exponential)
  -n INT: the number of connections to open (round robin/random mode)

  connection modes: per_request, round_robin, random
  service distribution: fixed, exp, lognorm
```

Where the `exp. service us` argument specifies how long we expect the
application packet to take to process once received by the server (this is,
computation time). This argument is only supported by the synthetic protocol.
The synthetic protocol includes this value in a packet and the server does that
wall-clock amount of work (on a single core) before replying.

Once all the requested samples have been collected, output as follows will be
produced:

``` sh
#reqs/s: hit        target
         10.260609  10.0000 

service: min  avg      std      99th  99.9th  max
         183  1690.05  1430.51  6711  8665    8665

 buffer: min  avg      std      99th  99.9th  max
         183  1690.05  1430.51  6711  8665    8665

   wait: min  avg     std     99th  99.9th  max
         0    464.02  311.93  1746  1938    1938
```

For the first group, the first column gives the achieved requests/sec while,
the second gives the targeted request/sec rate.

For the second group, service is the time to service a packet (total RTT) after
it has been generated according to the schedule.

The third group, buffer, gives the time a packet spent queue on the load
generator before transmission over the network (or at least, to kernel-space).
It ideally should be close to zero, and if not, indicates queueing from either
the network, or blocking on the server side. This is somewhat like queuing
delay but innacurate as it can only measure the time spent in userspace at the
load generator, not the time spent queued in the kernel or at the server.

The fourth group, wait, is the total queueing delay (accurate!). The queueing
delay can only be calculated for protocols that explicitly support it (the
service time for an application must be known a-priori).

## What latency are we measuring?

Firstly, at the start of an experiment run, we generate the complete packet
schedule (transmit time for each application packet) that we will use.
Secondly, we use our own socket abstraction that includes very large userspace
tx and rx buffers. Application packets are generated on schedule and copied to
the tx buffer. Should the tx buffer be full, we crash rather than block.

The combination of these two design features allows us to notice when the
generating machine can't hit it's expected schedule. If we our timers to
generate application packets are behind schedule, then it can only be due to
the machine being under too much load, as all network blocking has been
removed. This gives us a lot more confidence than other tools in removing the
latency of the measurement machine from the measurements.

Finally, we generate two timestamps when transmitting an application packet:

1) We generate a timestamp once we have copied the fresh application packet to
the socket tx buffer, but before we attempt to transmit any of the tx buffer.
2) We generate a second timestamp for that application packet once it has
actually been written to the kernel / NIC.

The difference between these two timestamps allows us some measure of client
side queuing, due either to blocking on the NIC, in the network, or on the
server side.

## Design

We take several design lessons from our previous experience building and
working with [mutilate](https://github.com/leverich/mutilate):

* **Single threaded**: launch multiple mutated processes to generate more load
  if required.
* **Multi-agent orchestration out-of-band**: mutilate supported a network
  protocol to coordinate a set of mutilate processes to generate load, allowing
  the use of multiple machines. Mutated can be used this way too but pushes
  this out of the core code, instead just relying on generic process
  coordination using shell scripts.
* **Data loading out-of-band**: mutilate was fairly specific to memcached,
  supporting loading an initial data set into the server. Mutated avoids this,
  instead relying on separate tools (although distributed with mutated) for
  loading the testing data before starting mutated.
* **Collect all results**: we record every single sample. We want to be able to
  find any and all latency issues.
* **Open system**: we generate packets as an open system. In particular, we do
  this by fixing the entire packet schedule ahead of time so that we know when
  we aren't hitting our expected transmission rate, and to keep the hot-path
  (packet transmission) as fast as possible.
* **Fast hot-path**: we try to avoid any allocation and as much work as
  possible on the packet transmission path (hot-path) to ensure as little noise
  caused by mutated itself.

The overall theme compared to mutilate is one of simplifying and reducing the
core concern to only packet generation and latency sampling. Agent
coordination, initial test-data loading, post-sample result processing are all
pushed into separate tools to keep mutated as lean and simple as possible.

## Building

This project uses automake and autoconf for its build system. To build:

``` sh
git submodule update --init
./autogen.sh
./configure
make
```

It requires a recent C++14 compiler (GCC or Clang should both work) and has
only been tested on Linux. Support for BSD's should be possible, but will
require abstracting the epoll implementation.

## Coding style

We use `clang-format` to enforce a coding style and avoid bike-shedding
arguments. Please run `make format` to format the code before committing your
changes.

Beyond `clang-format`, for issues such as naming conventions.. etc, we use the
[Google C++ style guide](https://google.github.io/styleguide/cppguide.html).

We deviate from it in the following ways:

* Method names: we use lowercase and underscores, i.e., `method_one`, not
  camel-case as they recommend `MethodOne`.
* Type names: generally camel-case, e.g., `Accum`, `SockBuf`, but fine to use
  camel-case when it's a cheap ('primitive') type, or a alias for an existing
  C++ type that is lowercase, e.g., `using clock = std::chrono::steady_clock;`.
  Finally, for our own container types (e.g., `buffer`), we use lowercase to
  match C++ STL.

We also make use of `cppcheck` and `clang-check` static analysis tools to look
for bugs. Please check your changes with `make cppcheck` and `make clang-scan`.
We keep the code free of all warnings at all times.

## Get involved!

We are happy to receive bug reports, fixes, documentation enhancements,
and other improvements.

Please report bugs via the
[github issue tracker](http://github.com/scslab/mutated/issues).

Master [git repository](http://github.com/scslab/mutated):

* `git clone git://github.com/scslab/mutated.git`

## Authors

Please see [AUTHORS](AUTHORS) for the list of contributors. In general though,
mutated is written by the [Stanford Secure Computing
Systems](http://www.scs.stanford.edu/) group.

