#ifndef MUTATED_GEN_MEMCACHE_HH
#define MUTATED_GEN_MEMCACHE_HH

#include <cstdint>
#include <random>

#include "generator.hh"
#include "limits.hh"
#include "memcache.hh"
#include "opts.hh"
#include "socket_buf.hh"

/**
 * Generator supporting the memcache binary protocol.
 */
class Memcache : public Generator
{
  private:
    /**
     * Tracks an outstanding memcache request.
     */
    struct MemReq {
        using RequestCB = Generator::RequestCB;
        using time_point = Generator::time_point;

        MemcCmd op;
        bool measure;
        RequestCB cb;
        time_point start_ts;
        time_point sent_ts;

        MemReq(void) noexcept : MemReq(MemcCmd::Get, false, nullptr) {}

        MemReq(MemcCmd o, bool m, RequestCB c) noexcept : op{o},
                                                          measure{m},
                                                          cb{c},
                                                          start_ts{},
                                                          sent_ts{}
        {
        }
    };

    /* Buffer for tracking requests outstanding */
    using req_buffer = buffer<MemReq, MAX_OUTSTANDING_REQS>;

    const Config &cfg_;
    std::mt19937 rand_;
    std::uniform_real_distribution<> setget_;
    IORx::CB rcb_;
    IOTx::CB tcb_;
    req_buffer requests_;
    uint64_t seqid_;

    MemcCmd choose_cmd(void);
    char *choose_key(uint64_t id, uint16_t &n);
    char *choose_val(uint64_t id, uint32_t &n);

    void sent_request(Sock *s, void *data, int status);
    size_t recv_response(Sock *sock, void *data, char *seg1, size_t n,
                         char *seg2, size_t m, int status);

  protected:
    uint64_t _send_request(bool measure, RequestCB cb) override;

  public:
    Memcache(const Config &cfg, std::mt19937 &&rand);
    ~Memcache(void) noexcept {}

    /* No copy or move */
    Memcache(const Memcache &) = delete;
    Memcache(Memcache &&) = delete;
    Memcache &operator=(const Memcache &) = delete;
    Memcache &operator=(Memcache &&) = delete;
};

#endif /* MUTATED_GEN_MEMCACHE_HH */
