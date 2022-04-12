#include <fstream>
#include <functional>
#include <string>

#include <inttypes.h>
#include <fcntl.h>

#include "client.hh"
#include "gen_memcache.hh"
#include "gen_synthetic.hh"
#include "generator.hh"
#include "linux_compat.hh"
#include "socket_buf.hh"
#include "util.hh"

using namespace std;
using namespace std::placeholders;

/**
 * Create a new client.
 */
Client::Client(Config c)
  : cfg_{c}
  , rd_{}
  , randgen_{rd_()}
  , conn_dist_{0, (int)cfg_.conn_cnt - 1}
  , gen_cb_{bind(&Client::record_sample, this, _1, _2, _3, _4, _5, _6)}
  , epollfd_{system_call(epoll_create1(0), "Client::Client: epoll_create1()")}
  , timerfd_{system_call(timerfd_create(CLOCK_MONOTONIC, O_NONBLOCK),
                         "Client::Client: timefd_create()")}
  , results_{cfg_.samples}
  , sent_count_{0}
  , rcvd_count_{0}
  , measure_count_{0}
  , pre_samples_{0}
  , post_samples_{0}
  , measure_samples_{0}
  , total_samples_{0}
  , exp_start_time_{}
  , deadlines_{}
  , missed_threshold_{-cfg_.missed_window_us * 1000}
  , missed_send_{0}
  , conns_{}
{
    epoll_watch(timerfd_, NULL, EPOLLIN);
}

/**
 * Destructor.
 */
Client::~Client(void) noexcept
{
    close(epollfd_);
    close(timerfd_);
}

/**
 * epoll_watch - registers a file descriptor for epoll events.
 * @fd: the file descriptor.
 * @data: a cookie for the event.
 * @event: the event mask.
 */
void Client::epoll_watch(int fd, void *data, uint32_t events)
{
    epoll_event ev;
    ev.events = events | EPOLLET;
    ev.data.ptr = data;
    system_call(epoll_ctl(epollfd_, EPOLL_CTL_ADD, fd, &ev),
                "Client::epoll_watch: epoll_ctl()");
}

/**
 * Set timer to fire in usec time *since the last timer firing*
 * (as recorded by last_time). This means if you call timer_arm()
 * with a sequence of usecs based on some probability distribution,
 * the timer will trigger will according to that distribution,
 * and not the distribution + processing time.
 */
void Client::timer_arm(duration deadline)
{
    itimerspec itval;
    itval.it_interval.tv_sec = 0;
    itval.it_interval.tv_nsec = 0;
    itval.it_value.tv_sec = deadline.count() / NSEC;
    itval.it_value.tv_nsec = deadline.count() - itval.it_value.tv_sec * NSEC;

    system_call(timerfd_settime(timerfd_, 0, &itval, NULL),
                "Client::timer_arm: timerfd_settime()");
}

/**
 * Run a client, generate load and measure repsonse times.
 */
void Client::run(void)
{
    // Maximum outstanding epoll events supported
    constexpr size_t MAX_EVENTS = 4096;
    epoll_event events[MAX_EVENTS];
    int epoll_timeout = -1;
    if (cfg_.use_busy_timer) {
        epoll_timeout = 0;
    }

    setup_experiment();

    while (true) {
        int nfds;

        if (cfg_.use_epoll_spin) {
            nfds = system_call(epoll_spin(epollfd_, events, MAX_EVENTS,
                               epoll_timeout), "Client::run: epoll_spin()");
        } else {
            nfds = system_call(epoll_wait(epollfd_, events, MAX_EVENTS,
                               epoll_timeout), "Client::run: epoll_wait()");
        }

        for (int i = 0; i < nfds; i++) {
            epoll_event &ev = events[i];
            if (ev.data.ptr == nullptr) {
                if (cfg_.use_busy_timer) {
                    throw runtime_error("timer event when using busy timer");
                }
                timer_handler();
            } else {
                Generator *g = reinterpret_cast<Generator *>(ev.data.ptr);
                g->run_io(ev.events);
            }
        }

        if (cfg_.use_busy_timer) {
            busy_timer();
        }
    }
}

void Client::setup_experiment(void)
{
    setup_connections();
    setup_deadlines();
    exp_start_time_ = clock::now();
    if (not cfg_.use_busy_timer) {
        timer_handler();
    }
}

void Client::setup_deadlines(void)
{
    // Exponential distribution suggested by experimental evidence,
    // c.f. Figure 11 in "Power Management of Online Data-Intensive Services"
    std::exponential_distribution<double> d(1.0 / (NSEC / cfg_.req_s));
    double accum = 0;
    uint64_t pos = 0;
    duration coolstart;

    // generate warm-up samples
    while (duration(uint64_t(ceil(accum))) <
           std::chrono::seconds(cfg_.warmup_seconds)) {
        accum += d(randgen_);
        deadlines_.push_back(duration(uint64_t(ceil(accum))));
        pos++;
    }
    pre_samples_ = pos;

    // generate measurement samples
    while (pos - pre_samples_ < cfg_.samples) {
        accum += d(randgen_);
        deadlines_.push_back(duration(uint64_t(ceil(accum))));
        pos++;
    }
    measure_samples_ = cfg_.samples;

    // generate cool-down samples
    coolstart = duration(uint64_t(ceil(accum)));
    while (duration(uint64_t(ceil(accum))) - coolstart <
           std::chrono::seconds(cfg_.cooldown_seconds)) {
        accum += d(randgen_);
        deadlines_.push_back(duration(uint64_t(ceil(accum))));
        pos++;
    }
    post_samples_ = pos - pre_samples_ - measure_samples_;
    total_samples_ = pos;
}

/**
 * Create a new socket and associated packet generator.
 */
Generator *Client::new_connection(void)
{
    Generator *gen;
    switch (cfg_.protocol) {
    case Config::SYNTHETIC:
        gen = new Synthetic(cfg_, randgen_);
        break;
    case Config::MEMCACHE:
        gen = new Memcache(cfg_, mt19937(rd_()));
        break;
    default:
        throw runtime_error("Unknown protocol");
        break;
    }

    gen->connect(cfg_.addr, cfg_.port);
    epoll_watch(gen->fd(), gen, EPOLLIN | EPOLLOUT);
    return gen;
}

void Client::setup_connections(void)
{
    if (cfg_.conn_mode == cfg_.PER_REQUEST) {
        return;
    }

    for (size_t i = 0; i < cfg_.conn_cnt; i++) {
        conns_.push_back(new_connection());
    }
}

Generator *Client::get_connection(void)
{
    if (cfg_.conn_mode == cfg_.PER_REQUEST) {
        // create a new connection per request
        return new_connection();
    } else if (cfg_.conn_mode == cfg_.ROUND_ROBIN) {
        // round-robin through a pool of established connections
        static int idx = 0;
        Generator *gen = conns_[idx++ % conns_.size()];
        gen->get();
        return gen;
    } else {
        // randomly choose a connection from the pool
        Generator *gen = conns_[conn_dist_(randgen_)];
        gen->get();
        return gen;
    }
}

void Client::timer_handler(void)
{
    time_point now_time = clock::now();
    duration now_relative =
      chrono::duration_cast<duration>(now_time - exp_start_time_);

    uint64_t looped = 0;
    duration sleep_duration;
    while (true) {
        sleep_duration = deadlines_[sent_count_] - now_relative;
        if (sleep_duration > duration(0)) {
            timer_arm(sleep_duration);
            return;
        } else if (looped > 0 and sleep_duration < missed_threshold_) {
            // Missed timer! Client appears to be overloaded...
            // TODO: Best way to detect and record?
            missed_send_++;
        }
        looped++;
        send_request();
        sent_count_++;
        if (sent_count_ >= total_samples_) {
            return;
        }
    }
}

void Client::busy_timer(void)
{
    time_point now = clock::now();
    duration d = deadlines_[sent_count_] + exp_start_time_ - now;

    while (d <= duration(0) and sent_count_ < total_samples_) {
        if (d < missed_threshold_) {
            missed_send_++;
        }
        send_request();
        sent_count_++;
        d = deadlines_[sent_count_] + exp_start_time_ - now;
    }
}

void Client::send_request(void)
{
    if (sent_count_ == pre_samples_) {
        results_.start_measurements();
    }

    // in measure phase? (not warm up or down)
    bool measure = sent_count_ >= pre_samples_ and
                   sent_count_ < pre_samples_ + measure_samples_;

    // gen is reference counted (get/put, starts at 1) and we'll deallocate it
    // in `record_sample`.
    Generator *gen = get_connection();
    uint64_t bytes = gen->send_request(measure, gen_cb_);
    if (measure) {
        results_.sent_bytes(bytes);
    }
}

/**
 * Record a latency sample.
 */
void Client::record_sample(Generator *conn, uint64_t queue_us,
                           uint64_t service_us, uint64_t wait_us,
                           uint64_t bytes, bool measure)
{
    if (measure) {
        measure_count_++;
        results_.add_sample(queue_us, service_us, wait_us, bytes);

        // final measurement app-packet - record experiment time
        if (measure_count_ == measure_samples_) {
            results_.end_measurements();
        }
    }

    conn->put(); // request finished

    rcvd_count_++;
    if (rcvd_count_ >= total_samples_) {
        print_summary();
        record_iatimes();
        exit(EXIT_SUCCESS);
    }
}

/**
 * Print summary of current results.
 *
 * NB: Keep this up to date with 'Client::print_header()'.
 */
void Client::print_summary(void)
{
    if (cfg_.machine_readable) {
        printf("%f\n", results_.reqps());
        results_.service().print_samples();
        return;
    }

    cout << "#reqs/s: hit\t\ttarget" << endl;
    printf("         %f\t%f\t\n", results_.reqps(), cfg_.req_s);
    cout << endl;

    cout << "service: min\tavg\t\tstd\t\t50th\t90th\t95th\t99th\tmax" << endl;
    printf("         %" PRIu64 "\t%f\t%f\t%" PRIu64 "\t%" PRIu64 "\t%" PRIu64 "\t%" PRIu64 "\t%" PRIu64
           "\n",
           results_.service().min(), results_.service().mean(),
           results_.service().stddev(), results_.service().percentile(0.50),
           results_.service().percentile(0.90), results_.service().percentile(0.95),
           results_.service().percentile(0.99), results_.service().max());
    cout << endl;

    cout << " buffer: min\tavg\t\tstd\t\t95th\t99th\tmax" << endl;
    printf("         %" PRIu64 "\t%f\t%f\t%" PRIu64 "\t%" PRIu64 "\t%" PRIu64
           "\n",
           results_.queue().min(), results_.queue().mean(),
           results_.queue().stddev(), results_.queue().percentile(0.95),
           results_.queue().percentile(0.99), results_.queue().max());

    if (cfg_.protocol == Config::SYNTHETIC) {
        cout << endl;
        cout << "   wait: min\tavg\t\tstd\t\t95th\t99th\tmax" << endl;
        printf("         %" PRIu64 "\t%f\t%f\t%" PRIu64 "\t%" PRIu64
               "\t%" PRIu64 "\n",
               results_.wait().min(), results_.wait().mean(),
               results_.wait().stddev(), results_.wait().percentile(0.95),
               results_.wait().percentile(0.99), results_.wait().max());
    }

    constexpr uint64_t MB = 1024 * 1024;
    double time_s = results_.running_time() / NSEC;
    double rx_mbs = double(results_.rx_bytes()) / MB;
    double tx_mbs = double(results_.tx_bytes()) / MB;

    printf("\n");
    printf("RX: %.2f MB/s (%.2f MB)\n", rx_mbs / time_s, rx_mbs);
    printf("TX: %.2f MB/s (%.2f MB)\n", tx_mbs / time_s, tx_mbs);
    printf("Missed sends: %lu / %lu (%.4f%%)\n", missed_send_, sent_count_,
           double(missed_send_) / sent_count_ * 100);
}

/**
 * Record our deadline schedule to a file for offline evaluation.
 */
void Client::record_iatimes(void)
{
    if (cfg_.save_iatimes != nullptr) {
        duration last{0};
        ofstream f(cfg_.save_iatimes);
        for (auto t : deadlines_) {
            if (last == duration(0)) {
                last = t;
            } else {
                f << (t - last).count() << "\n";
                last = t;
            }
        }
        f.close();
    }
}
