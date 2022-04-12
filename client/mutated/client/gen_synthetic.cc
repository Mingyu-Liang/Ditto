#include <chrono>
#include <functional>
#include <iostream>
#include <memory>
#include <stdexcept>

#include <errno.h>

#include "gen_synthetic.hh"
#include "socket_buf.hh"
#include "util.hh"

using namespace std;
using namespace std::placeholders;

/**
 * Constructor.
 */
Synthetic::Synthetic(const Config &cfg, mt19937 &rand) noexcept
  : cfg_(cfg),
    rand_{rand},
    service_dist_exp_{1.0 / cfg.service_us},
    service_dist_lognorm_{log(cfg.service_us) - 2.0, 2.0},
    rcb_{bind(&Synthetic::recv_response, this, _1, _2, _3, _4, _5, _6, _7)},
    tcb_{bind(&Synthetic::sent_request, this, _1, _2, _3)},
    requests_{}
{
}

/**
 * Return a service time to use for the next SynReq.
 */
uint64_t Synthetic::gen_service_time(void)
{
    if (cfg_.service_dist == cfg_.FIXED) {
        return ceil(cfg_.service_us);
    } else if (cfg_.service_dist == cfg_.EXPONENTIAL) {
        return ceil(service_dist_exp_(rand_));
    } else {
        return ceil(service_dist_lognorm_(rand_));
    }
}

/**
 * Generate and send a new request.
 */
uint64_t Synthetic::_send_request(bool measure, RequestCB cb)
{
    // create our SynReq
    SynReq &req = requests_.queue_emplace(measure, cb, gen_service_time());
    // size_t n = sizeof(req_pkt), n1 = n;
    // auto wptrs = sock_.write_prepare(n1);
    // if (n1 == n) {
    //     // contiguous
    //     req_pkt *pkt = (req_pkt *)wptrs.first;
    //     pkt->tag = (uint64_t)&req;
    //     pkt->noreply = cfg_.send_only;
    //     pkt->nr = 1;
    //     pkt->delays[0] = req.service_us;
    // } else {
    //     // fragmented
    //     req_pkt pkt;
    //     pkt.tag = (uint64_t)&req;
    //     pkt.noreply = cfg_.send_only;
    //     pkt.nr = 1;
    //     pkt.delays[0] = req.service_us;
    //     memcpy(wptrs.first, &pkt, n1);
    //     memcpy(wptrs.second, &pkt + n1, n - n1);
    // }

    // req_pkt *pkt = new req_pkt;
    // pkt->tag = (uint64_t)&req;
    // pkt->noreply = cfg_.send_only;
    // pkt->nr = 1;
    // pkt->delays[0] = req.service_us;
    // sock_.write(pkt, sizeof(req_pkt));
    size_t bodlen = cfg_.pkt_size;
    sock_.write_prepare(bodlen);
    sock_.write_commit(bodlen);

    // setup timestamps
    req.start_ts = Generator::clock::now();
    sock_.write_cb_point(tcb_, &req);

    // try transmission
    sock_.try_tx();

    // add response to read queue
    IORx io(sizeof(resp_pkt), rcb_, 0, nullptr, &req);
    sock_.read(io);

    // fake response if send-only mode
    if (cfg_.send_only) {
        req.cb(this, 0, 0, 0, 0, measure);
    }

    return bodlen;
}

/**
 * Handle marking a generated synthetic request as sent.
 */
void Synthetic::sent_request(Sock *s, void *data, int status)
{
    if (&sock_ != s) { // ensure right callback
        throw runtime_error(
          "Synthetic::sent_request: wrong socket in callback");
    } else if (status != 0) { // just return on error
        return;
    }

    // add in sent timestamp to packet
    SynReq *req = reinterpret_cast<SynReq *>(data);
    req->sent_ts = Generator::clock::now();
}

/**
 * Handle parsing a response from a previous request.
 */
size_t Synthetic::recv_response(Sock *s, void *data, char *seg1, size_t n,
                                char *seg2, size_t m, int status)
{
    UNUSED(seg1);
    UNUSED(seg2);

    if (&sock_ != s) { // ensure right callback
        throw runtime_error(
          "Synthetic::recv_response: wrong socket in callback");
    }

    if (status != 0) { // just drop on error
        requests_.drop(1);
        return 0;
    } else if (n + m != sizeof(resp_pkt)) { // ensure valid packet
        throw runtime_error(
          "Synthetic::recv_response: unexpected packet size");
    }

    // parse packet
    const SynReq &req = requests_.dequeue_one();
    if (data != &req) {
        throw runtime_error(
          "Synthetic::recv_response: wrong response-request packet match");
    }
    auto now = Generator::clock::now();

    // client-side queue time
    auto delta = req.sent_ts - req.start_ts;
    if (delta <= Generator::duration(0)) {
        throw std::runtime_error(
          "Synthetic::recv_response: sent before it was generated");
    }
    uint64_t queue_us =
      chrono::duration_cast<Generator::duration>(delta).count();

    // service time
    delta = now - req.start_ts;
    if (delta <= Generator::duration(0)) {
        throw std::runtime_error(
          "Synthetic::recv_response: arrived before it was sent");
    }
    uint64_t service_us =
      chrono::duration_cast<Generator::duration>(delta).count();

    // wait time
    uint64_t wait_us;
    if (service_us > req.service_us) {
        wait_us = service_us - req.service_us;
    } else {
        // measurement noise can push wait_us into negative values sometimes
        wait_us = 0;
    }
    req.cb(this, queue_us, service_us, wait_us, sizeof(resp_pkt), req.measure);

    // no body, only a header
    return 0;
}
