# TODO

Todo notes for mutated.

## Project

* Travis CI
* Tests!
* Coveralls
* Coverity

## Core

* Better sizing approach to buffers (charbuf and request queues).
* Cleanup how multiple protocols are supported.
* Pull common code out of client into own lib.
* Should loaders be explicitly supported or out-of-band?
* Support varying (how to specify?) workload intensity (i.e., not a constant
  req/s rate).
* Should the rx loop be run till blocking? Or is their a live-lock issue with
  this approach?

## Cross-OS

* Support FreeBSD/OSX.

## Memcached

Loader:
* Support key-value size distributions beyond fixed.
* Pull loader into own folder (core cleaning needed).

Generator:
* Support setting hit/miss ratio - maybe enough to just set different key set?
* Support distributions for schedule, key choice, and value size.

Mutilate Distributions:
* Request schedule  - fixed, uniform, normal, exponential, pareto, gev
* Choose operation  - fixed, uniform
* Choose key        - fixed
* Choose key sie    - fixed, uniform, normal, exponential, pareto, gev
* Choose value size - fixed, uniform, normal, exponential, pareto, gev

Mutated Distributions:
* Request schedule  - fixed, exponential, lognorm
* Choose operation  - fixed, uniform
* Choose key        - fixed
* Choose key size   - fixed
* Choose value size - fixed

