#ifndef MUTATED_GEN_SYNTHETIC_HH
#define MUTATED_GEN_SYNTHETIC_HH

#include <cstdint>
#include <random>

#include "buffer.hh"
#include "generator.hh"
#include "limits.hh"
#include "opts.hh"
#include "socket_buf.hh"

static constexpr uint32_t REQ_MAX_DELAYS = 16;

/**
 * Synthetic protocol request type.
 */
struct req_pkt {
    uint32_t nr;                     /* the number of delays */
    uint32_t noreply;                /* should the server send a reply? */
    uint64_t tag;                    /* a unique indentifier for the request */
    uint64_t delays[REQ_MAX_DELAYS]; /* an array of delays */
} __attribute__((packed));

/**
 * Synthetic protocol response type.
 */
struct resp_pkt {
    uint64_t tag;
} __attribute__((packed));

/**
 * Generator supporting our own mutated synthetic protocol.
 */
class Synthetic : public Generator
{
  private:
    /**
     * Tracks an outstanding synthetic request.
     */
    struct SynReq {
        using RequestCB = Generator::RequestCB;
        using time_point = Generator::time_point;

        bool measure;
        RequestCB cb;
        time_point start_ts;
        time_point sent_ts;
        uint64_t service_us;

        SynReq(void) noexcept : SynReq(false, nullptr, 0) {}

        SynReq(bool m, RequestCB c, uint64_t service) noexcept
          : measure{m},
            cb{c},
            start_ts{},
            sent_ts{},
            service_us{service}
        {
        }
    };

    /* Buffer for tracking requests outstanding */
    using req_buffer = buffer<SynReq, MAX_OUTSTANDING_REQS>;

    const Config &cfg_;
    std::mt19937 &rand_;
    std::exponential_distribution<double> service_dist_exp_;
    std::lognormal_distribution<double> service_dist_lognorm_;
    IORx::CB rcb_;
    IOTx::CB tcb_;
    req_buffer requests_;

    uint64_t gen_service_time(void);
    void sent_request(Sock *s, void *data, int status);
    size_t recv_response(Sock *sock, void *data, char *seg1, size_t n,
                         char *seg2, size_t m, int status);

  protected:
    uint64_t _send_request(bool measure, RequestCB cb) override;

  public:
    Synthetic(const Config &cfg, std::mt19937 &rand) noexcept;
    ~Synthetic(void) noexcept {}

    /* No copy or move */
    Synthetic(const Synthetic &) = delete;
    Synthetic(Synthetic &&) = delete;
    Synthetic &operator=(const Synthetic &) = delete;
    Synthetic &operator=(Synthetic &&) = delete;
};

#endif /* MUTATED_GEN_SYNTHETIC_HH */
