#include <chrono>
#include <functional>
#include <iostream>
#include <stdexcept>

#include <arpa/inet.h>
#include <errno.h>
#include <inttypes.h>

#include "memcache.hh"
#include "gen_memcache.hh"
#include "socket_buf.hh"
#include "util.hh"

using namespace std;
using namespace std::placeholders;

// XXX: Future work:
// - Support choosing key with a distribution
// - Support variable value size with SET workload (distribution)

/* Size of fmt string for generating keys */
static constexpr std::size_t KEYFMT_SIZE = 30;

/* Key generation */
static bool _kv_setup = false;
static char _keyfmt[KEYFMT_SIZE];
static char *_keys = nullptr;
static char *_val = nullptr;

/**
 * Construct.
 */
Memcache::Memcache(const Config &cfg, std::mt19937 &&rand)
  : cfg_{cfg},
    rand_{move(rand)},
    setget_{0, 1.0},
    rcb_{bind(&Memcache::recv_response, this, _1, _2, _3, _4, _5, _6, _7)},
    tcb_{bind(&Memcache::sent_request, this, _1, _2, _3)},
    requests_{},
    seqid_{rand_()} // start from random sequence id
{
    UNUSED(cfg_);

    // create all needed requests upfront
    if (not _kv_setup) {
        _kv_setup = true;

        // create the fmt string for creating keys (TODO: better way than
        // this?)
        // KEYFMT: <000000...N>
        int n = snprintf(_keyfmt, KEYFMT_SIZE, "%%0%" PRIu64 "%s",
                         cfg_.keysize, PRIu64);
        if (uint64_t(n) >= KEYFMT_SIZE) {
            throw runtime_error(
              "Memcache::Memcache: fmt buffer for printing keys too small");
        }

        // create keys
        _keys = new char[cfg_.records * (cfg_.keysize + 1)];
        for (size_t i = 1; i <= cfg_.records; i++) {
            char *buf = &_keys[(i - 1) * (cfg_.keysize + 1)];
            snprintf(buf, cfg_.keysize + 1, _keyfmt, i);
        }

        // create value(s)
        _val = new char[cfg_.valsize];
        memset(_val, 'a', cfg_.valsize);
    }
}

MemcCmd Memcache::choose_cmd(void)
{
    if (setget_(rand_) < cfg_.setget) {
        return MemcCmd::Set;
    } else {
        return MemcCmd::Get;
    }
}

char *Memcache::choose_key(uint64_t id, uint16_t &n)
{
    n = cfg_.keysize;
    return &_keys[(id % cfg_.records) * (cfg_.keysize + 1)];
}

char *Memcache::choose_val(uint64_t id, uint32_t &n)
{
    UNUSED(id);
    n = cfg_.valsize;
    return _val;
}

/**
 * Generate and send a new request.
 */
uint64_t Memcache::_send_request(bool measure, RequestCB cb)
{
    uint64_t id = seqid_++;
    uint16_t keylen;
    uint32_t bodlen;
    char *key;

    // create our request
    MemcCmd op = choose_cmd();
    key = choose_key(id, keylen);

    // add req to write queue
    if (op == MemcCmd::Get) {
        sock_.write_emplace<MemcHeader>(MemcType::Request, op, 0, keylen, 0);
        sock_.write(key, keylen);
        bodlen = keylen;
    } else {
        sock_.write_emplace<MemcHeader>(
          MemcType::Request, op, sizeof(MemcExtrasSet), keylen, cfg_.valsize);
        sock_.write_emplace<MemcExtrasSet>();
        sock_.write(key, keylen);

        // just write random bytes for the value
        size_t vn = cfg_.valsize;
        sock_.write_prepare(vn);
        sock_.write_commit(cfg_.valsize);
        bodlen = keylen + sizeof(MemcExtrasSet) + cfg_.valsize;
    }

    // setup timestamps
    MemReq &req = requests_.queue_emplace(op, measure, cb);
    req.start_ts = Generator::clock::now();
    sock_.write_cb_point(tcb_, &req);

    // try transmission
    sock_.try_tx();

    // add response to read queue
    IORx io(MemcHeader::SIZE, rcb_, 0, nullptr, &req);
    sock_.read(io);

    return MemcHeader::SIZE + bodlen;
}

/**
 * Handle marking a generated memcache request as sent.
 */
void Memcache::sent_request(Sock *s, void *data, int status)
{
    if (&sock_ != s) { // ensure right callback
        throw runtime_error(
          "Memcache::sent_request: wrong socket in callback");
    } else if (status != 0) { // just return on error
        return;
    }

    // add in sent timestamp to packet
    MemReq *req = reinterpret_cast<MemReq *>(data);
    req->sent_ts = Generator::clock::now();
}

/**
 * Handle parsing a response from a previous request.
 */
size_t Memcache::recv_response(Sock *s, void *data, char *seg1, size_t n,
                               char *seg2, size_t m, int status)
{
    if (&sock_ != s) { // ensure right callback
        throw runtime_error(
          "Memcache::recv_response: wrong socket in callback");
    } else if (status != 0) { // just delete on error
        requests_.drop(1);
        return 0;
    } else if (n + m != MemcHeader::SIZE) { // ensure valid packet
        throw runtime_error("Memcache::recv_response: unexpected packet size");
    }

    // calculate measurement
    const MemReq &req = requests_.dequeue_one();
    if (data != &req) {
        throw runtime_error(
          "Memcache::recv_response: wrong response-request packet match");
    }
    auto now = Generator::clock::now();

    // client-side queue time
    auto delta = req.sent_ts - req.start_ts;
    if (delta <= Generator::duration(0)) {
        throw std::runtime_error(
          "Memcache::recv_response: sent before it was generated");
    }
    uint64_t queue_us =
      chrono::duration_cast<Generator::duration>(delta).count();

    // service time
    delta = now - req.start_ts;
    if (delta <= Generator::duration(0)) {
        throw std::runtime_error(
          "Memcache::recv_response: arrived before it was sent");
    }
    uint64_t service_us =
      chrono::duration_cast<Generator::duration>(delta).count();

    // parse packet - need to drop body
    uint32_t bodylen = 0;
    if (req.op != MemcCmd::Set) {
        if (seg2 == nullptr) {
            MemcHeader *hdr = reinterpret_cast<MemcHeader *>(seg1);
            bodylen = ntohl(hdr->bodylen);
        } else {
            MemcHeader hdr;
            memcpy(&hdr, seg1, n);
            memcpy(&hdr + n, seg2, m);
            bodylen = ntohl(hdr.bodylen);
        }
    }

    // record result
    req.cb(this, queue_us, service_us, 0, MemcHeader::SIZE + bodylen,
           req.measure);

    return bodylen;
}
