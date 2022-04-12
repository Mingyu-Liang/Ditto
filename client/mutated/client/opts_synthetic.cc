/**
 * opts_synthetic.cc - Command line parser for synthetic protocol.
 */

#include <cmath>
#include <iostream>

#include <unistd.h>
#include <string.h>

#include "opts.hh"

using namespace std;

/* Fixed arguments required. */
static constexpr size_t FIXED_ARGS = 3;

/* Default number of seconds to sample for. */
static constexpr uint64_t DEFAULT_SAMPLE_S = 10;

/**
 * Print usage message and exit with status.
 */
static void __printUsage(string prog, int status = EXIT_FAILURE)
{
    if (status != EXIT_SUCCESS) {
        cerr << "invalid arguments!" << endl << endl;
    }

    cerr << "Usage: " << prog << " [options] "
         << "<ip:port> <exp. service us> <req/sec>" << endl
         << endl;
    cerr << "Common options:" << endl;
    cerr << "  -h    : help" << endl;
    cerr << "  -r    : print raw samples" << endl;
    cerr << "  -e    : use Shinjuku's epoll_spin() system call" << endl;
    cerr << "  -b    : use busy spin for timers" << endl;
    cerr << "  -i STR: file to save inter-arrival times to" << endl;
    cerr << "  -w INT: warm-up seconds (default: 5s)" << endl;
    cerr << "  -c INT: cool-down seconds (default: 5s)" << endl;
    cerr << "  -s INT: measurement seconds (default: 10s)" << endl;
    cerr << "  -W INT: missed send threshold microseconds (default: 100us)"
         << endl;
    cerr << "  -l STR: label for machine-readable output (-r)" << endl;
    cerr << "  -m OPT: connection mode (default: round_robin)" << endl;
    cerr << "  -d OPT: service time distribution (default: exponential)"
         << endl;
    cerr << "  -n INT: number of connections to open (round robin/random "
            "mode)"
         << endl;
    cerr << endl;
    cerr << "Synthetic options:" << endl;
    cerr << "  -z    : send requests only, don't expect response" << endl;
    cerr << "  -p    : send packet size in bytes (default: 32B)"  << endl;
    cerr << endl;
    cerr << "  connection modes: per_request, round_robin, random" << endl;
    cerr << "  service distribution: fixed, exp, lognorm" << endl;

    exit(status);
}

/**
 * Command line parser for synthetic protocol.
 */
Config parse_synthetic(int argc, char *argv[])
{
    Config cfg;
    int ret, c;
    opterr = 0;

    cfg.protocol = Config::SYNTHETIC;

    while ((c = getopt(argc, argv, "hrebzi:w:s:c:W:l:m:d:n:p:")) != -1) {
        switch (c) {
        case 'h':
            __printUsage(argv[0], EXIT_SUCCESS);
        case 'r':
            cfg.machine_readable = true;
            break;
        case 'e':
            cfg.use_epoll_spin = true;
            break;
        case 'b':
            cfg.use_busy_timer = true;
            break;
        case 'z':
            cfg.send_only = true;
            break;
        case 'i':
            cfg.save_iatimes = optarg;
            break;
        case 'w':
            cfg.warmup_seconds = atoi(optarg);
            break;
        case 's':
            cfg.samples = atoi(optarg);
            break;
        case 'c':
            cfg.cooldown_seconds = atoi(optarg);
            break;
        case 'W':
            cfg.missed_window_us = atoll(optarg);
            break;
        case 'l':
            cfg.label = optarg;
            break;
        case 'm':
            if (!strcmp(optarg, "per_request"))
                cfg.conn_mode = Config::PER_REQUEST;
            else if (!strcmp(optarg, "round_robin"))
                cfg.conn_mode = Config::ROUND_ROBIN;
            else if (!strcmp(optarg, "random"))
                cfg.conn_mode = Config::RANDOM;
            else
                __printUsage(argv[0]);
            break;
        case 'd':
            if (!strcmp(optarg, "fixed"))
                cfg.service_dist = Config::FIXED;
            else if (!strcmp(optarg, "exp"))
                cfg.service_dist = Config::EXPONENTIAL;
            else if (!strcmp(optarg, "lognorm"))
                cfg.service_dist = Config::LOG_NORMAL;
            else
                __printUsage(argv[0]);
            break;
        case 'n':
            cfg.conn_cnt = atoi(optarg);
            break;
        case 'p':
            cfg.pkt_size = atoi(optarg);
            break;
        default:
            __printUsage(argv[0]);
        }
    }

    if ((unsigned int)(argc - optind) < FIXED_ARGS) {
        __printUsage(argv[0]);
    }

    // NOTE: keep 256 in sync with addr buffer size.
    ret = sscanf(argv[optind + 0], "%256[^:]:%20hu", cfg.addr, &cfg.port);
    if (ret != 2) {
        __printUsage(argv[0]);
    }

    ret = sscanf(argv[optind + 1], "%20lf", &cfg.service_us);
    if (ret != 1) {
        __printUsage(argv[0]);
    }

    ret = sscanf(argv[optind + 2], "%20lf", &cfg.req_s);
    if (ret != 1) {
        __printUsage(argv[0]);
    }

    // convert from sample seconds to sample count
    if (cfg.samples == 0) {
        cfg.samples = DEFAULT_SAMPLE_S;
    }
    cfg.samples *= cfg.req_s;

    cfg.gen_argc = argc - optind - FIXED_ARGS;
    cfg.gen_argv = &argv[cfg.gen_argc];

    return cfg;
}
