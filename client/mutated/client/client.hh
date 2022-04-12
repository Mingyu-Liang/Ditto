#ifndef MUTATED_CLIENT_HH
#define MUTATED_CLIENT_HH

#include <chrono>
#include <memory>
#include <vector>

#include "generator.hh"
#include "opts.hh"
#include "results.hh"

/**
 * Mutated load generator.
 */
class Client
{
  private:
    using clock = std::chrono::steady_clock;
    using time_point = clock::time_point;
    using duration = std::chrono::nanoseconds;

    Config cfg_;

    std::random_device rd_;
    std::mt19937 randgen_;
    std::uniform_int_distribution<int> conn_dist_;
    Generator::RequestCB gen_cb_;

    unsigned int epollfd_;
    unsigned int timerfd_;

    Results results_;

    uint64_t sent_count_, rcvd_count_, measure_count_;
    uint64_t pre_samples_, post_samples_, measure_samples_, total_samples_;

    time_point exp_start_time_;
    std::vector<duration> deadlines_;
    duration missed_threshold_;
    uint64_t missed_send_;

    std::vector<Generator *> conns_;

    Generator *new_connection(void);
    void setup_connections(void);
    Generator *get_connection(void);
    void send_request(void);
    void epoll_watch(int fd, void *data, uint32_t events);
    void timer_arm(duration deadline);
    void timer_handler(void);
    void busy_timer(void);
    void setup_deadlines(void);
    void setup_experiment(void);
    void print_summary(void);
    void record_iatimes(void);

  public:
    explicit Client(Config c);
    ~Client(void) noexcept;

    /* No copy or move. */
    Client(const Client &) = delete;
    Client(Client &&) = delete;
    Client &operator=(const Client &) = delete;
    Client &operator=(Client &&) = delete;

    /* Run the load generator. */
    void run(void);

    /* Record a latency sample. */
    void record_sample(Generator *, uint64_t queue_us, uint64_t service_us,
                       uint64_t wait_us, uint64_t bytes, bool should_measure);
};

#endif /* MUTATED_CLIENT_HH */
