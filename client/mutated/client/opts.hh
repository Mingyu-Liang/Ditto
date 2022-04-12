#ifndef MUTATED_OPTS_HH
#define MUTATED_OPTS_HH

#include <cstdint>

/**
 * Options for mutated. We place all options for all supported protocols into
 * this one struct for now and rely of different command line parsers for each
 * protocol to populate it.
 *
 * TODO: Nicer, more idiomatic C++ way to compose parsers?
 * TODO: Unify common options among protocols (no copy-paste)
 */
struct Config {
    enum protocols {
        SYNTHETIC,
        MEMCACHE,
    };
    protocols protocol; /* protocol to speak */

    char addr[256];    /* the server address */
    uint16_t port;     /* the server port */
    const char *label; /* label describing server (-m relevant only) */

    double service_us; /* service time mean microseconds */
    double req_s;      /* requests per second */

    uint64_t warmup_seconds;   /* number of seconds to warm up */
    uint64_t cooldown_seconds; /* number of seconds to cool down */
    uint64_t samples;          /* number of samples to measure */

    bool machine_readable; /* generate machine readable output? */
    bool use_epoll_spin;   /* use the custom epoll_spin() system call */
    bool use_busy_timer;   /* busy spin for timers, not events */

    const char *save_iatimes; /* record iatimes to a file */

    enum conn_modes {
        PER_REQUEST,
        ROUND_ROBIN,
        RANDOM,
    };
    conn_modes conn_mode; /* the connection mode */
    uint64_t conn_cnt;    /* the number of connections to open */

    enum service_distributions {
        FIXED,
        EXPONENTIAL,
        LOG_NORMAL,
    };
    service_distributions service_dist; /* service time distribution */

    uint64_t missed_window_us; /* packet late send threshold */

    /* Synthetic options */
    bool send_only; /* only send requests, don't expect response */
    uint32_t pkt_size;

    /* Memcache options */
    uint64_t records; /* number of records to use */
    uint64_t keysize; /* size of keys (for gets/sets) */
    uint64_t valsize; /* size of values (for sets) */
    double setget;    /* set/get ratio */

    /* the remaining unparsed arguments */
    int gen_argc;
    char **gen_argv;

    /* Set defaults */
    Config(void)
      : protocol{SYNTHETIC}
      , addr{}
      , port{0}
      , label{"default"}
      , service_us{0}
      , req_s{0}
      , warmup_seconds{5}
      , cooldown_seconds{5}
      , samples{0}
      , machine_readable{false}
      , use_epoll_spin{false}
      , use_busy_timer{false}
      , save_iatimes{}
      , conn_mode{ROUND_ROBIN}
      , conn_cnt{10}
      , service_dist{EXPONENTIAL}
      , missed_window_us{100}
      , send_only{false}
      , pkt_size{32}
      , records{10000}
      , keysize{30}
      , valsize{4 * 1024}
      , setget{0.0}
      , gen_argc{0}
      , gen_argv{nullptr}

    {
    }
};

/* Parse command line for synthetic load generator */
Config parse_synthetic(int argc, char *argv[]);

/* Parse command line for memcache load generator */
Config parse_memcache(int argc, char *argv[]);

#endif /* MUTATED_OPTS_HH */
