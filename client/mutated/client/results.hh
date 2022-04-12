#ifndef MUTATED_RESULTS_HH
#define MUTATED_RESULTS_HH

#include <chrono>
#include <vector>
#include <stdexcept>

#include "accum.hh"
#include "util.hh"

/**
 * Results from a sampling run.
 */
class Results
{
  public:
    using clock = std::chrono::steady_clock;
    using time_point = clock::time_point;
    using duration = std::chrono::nanoseconds;

  private:
    time_point measure_start_;
    time_point measure_end_;
    Accum queue_;
    Accum service_;
    Accum wait_;
    uint64_t tx_bytes_;
    uint64_t rx_bytes_;
    double reqps_;

  public:
    explicit Results(std::size_t reserve) noexcept : measure_start_{},
                                                     measure_end_{},
                                                     queue_{reserve},
                                                     service_{reserve},
                                                     wait_{reserve},
                                                     tx_bytes_{0},
                                                     rx_bytes_{0},
                                                     reqps_{0}
    {
    }

    void start_measurements(void) noexcept { measure_start_ = clock::now(); }

    void end_measurements(void)
    {
        measure_end_ = clock::now();
        reqps_ = (double)service_.size() / (running_time() / NSEC);
    }

    uint64_t running_time(void)
    {
        auto length = measure_end_ - measure_start_;
        if (length <= clock::duration(0)) {
            throw std::runtime_error("experiment finished before it started");
        }
        return std::chrono::duration_cast<duration>(length).count();
    }

    void sent_bytes(uint64_t tx_bytes) noexcept { tx_bytes_ += tx_bytes; }

    void add_sample(uint64_t queue, uint64_t service, uint64_t wait,
                    uint64_t rx_bytes)
    {
        queue_.add_sample(queue);
        service_.add_sample(service);
        wait_.add_sample(wait);
        rx_bytes_ += rx_bytes;
    }

    Accum &queue(void) noexcept { return queue_; }
    Accum &service(void) noexcept { return service_; }
    Accum &wait(void) noexcept { return wait_; }

    double reqps(void) const noexcept { return reqps_; }
    uint64_t tx_bytes(void) const noexcept { return tx_bytes_; }
    uint64_t rx_bytes(void) const noexcept { return rx_bytes_; }
};

#endif /* MUTATED_RESULTS_HH */
