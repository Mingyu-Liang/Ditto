#ifndef MUTATED_MEMCACHE_HH
#define MUTATED_MEMCACHE_HH

/**
 * memcache.hh - representation of the memcache binary protocol.
 */

#include <cstdint>
#include <iostream>
#include <string>

#include "endian.hh"

// Memcache type of packet.
enum class MemcType : uint8_t {
    Request = 0x80,
    Response = 0x81,
};

// Memcache commands.
enum class MemcCmd : uint8_t {
    Get = 0x00,
    Set = 0x01,
    Add = 0x02,
    Replace = 0x03,
    Delete = 0x04,
    Increment = 0x05,
    Decrement = 0x06,
    Quit = 0x07,
    Flush = 0x08,
    Getq = 0x09,
    Noop = 0x0a,
    Version = 0x0b,
    Getk = 0x0c,
    Getkq = 0x0d,
    Append = 0x0e,
    Prepend = 0x0f,
    Stat = 0x10,
    Setq = 0x11,
    Addq = 0x12,
    Replaceq = 0x13,
    Deleteq = 0x14,
    Incrementq = 0x15,
    Decrementq = 0x16,
    Quitq = 0x17,
    Flushq = 0x18,
    Appendq = 0x19,
    Prependq = 0x1a,
    Verbosity = 0x1b, // memcache doesn't imp. but in spec;
    Touch = 0x1c,
    Gat = 0x1d,
    Gatq = 0x1e,
    Gatk = 0x23,
    Gatkq = 0x24,
    Sasl_list_mechs = 0x20,
    Sasl_auth = 0x21,
    Sasl_step = 0x22,
};

// Memcache status/error codes.
enum class MemcStatus : uint16_t {
    OK = 0x0000,
    ErrorKeyNotFound = 0x0001,
    ErrorKeyExists = 0x0002,
    ErrorValueTooLarge = 0x0003,
    ErrorInvalidArgument = 0x0004,
    ErrorItemNotStored = 0x0005,
    ErrorNonNumeric = 0x0006,
    ErrorAuthFailed = 0x0020,
    ErrorUnknownCommand = 0x0081,
    ErrorOutOfMemory = 0x0082,
    ErrorBusy = 0x0085,
};

// MemcHeader represents the header of a memcache binary protocl request or
// response.
struct MemcHeader {
    static constexpr std::size_t SIZE = 24;

    MemcType type;     // (aka 'magic) request or response?
    MemcCmd cmd;       // memcache operation
    uint16_t keylen;   // length of key
    uint8_t extralen;  // length of extras field
    uint8_t datatype;  // unused / reserved
    MemcStatus status; // success or failure of operation (response only)
    uint32_t bodylen;  // total body length (key + extra + value)
    uint32_t opaque;   // field associated with key-value controlable by user
    uint64_t version;  // version of key-value pair

    MemcHeader(void) noexcept
      : MemcHeader(MemcType::Request, MemcCmd::Get, 0, 0, 0)
    {
    }

    MemcHeader(MemcType t, MemcCmd c, uint8_t el, uint16_t kl,
               uint32_t vl) noexcept : type{t},
                                       cmd{c},
                                       keylen{kl},
                                       extralen{el},
                                       datatype{0},
                                       status{MemcStatus::OK},
                                       bodylen{el + kl + vl},
                                       opaque{0},
                                       version{0}
    {
        hton();
    }

    void hton(void)
    {
        keylen = htons(keylen);
        status = MemcStatus(htons(uint16_t(status)));
        bodylen = htonl(bodylen);
        opaque = htonl(opaque);
        version = htonll(opaque);
    }

    void ntoh(void)
    {
        keylen = ntohs(keylen);
        status = MemcStatus(ntohs(uint16_t(status)));
        bodylen = ntohl(bodylen);
        opaque = ntohl(opaque);
        version = ntohll(opaque);
    }
} __attribute__((packed));

/**
 * Construct a new memcache request header.
 */
inline MemcHeader MemcRequest(MemcCmd c, uint8_t el, uint16_t kl, uint32_t vl)
{
    return {MemcType::Request, c, el, kl, vl};
}

// Extras associated with some memcache commands.
struct MemcExtras {
};

// MemcExtrasSet represents the extra field for a set request.
struct MemcExtrasSet : public MemcExtras {
    uint32_t flags;
    uint32_t expiration;

    MemcExtrasSet(void) noexcept : flags{0}, expiration{0} {}
};

// MemcExtrasIncr represents the extra field for a increment/decrement request.
struct MemcExtrasIncr : public MemcExtras {
    uint64_t initial;
    uint64_t delta;
    uint32_t expiration;
};

// MemcExtrasTouch represents the extra field for a touch request.
struct MemcExtrasTouch : public MemcExtras {
    uint32_t expiration;
};

// MemcPacket represents (as best as possible in C++) a memcache
// request/response packet. This is contiguous on the wire but we can't
// represent that in C++ without a layer of indirection to capture the varaible
// sizing.
struct MemcPacket {
    MemcHeader *header;
    MemcExtras *extras;
    const char *key;
    const char *value;
};

/**
 * Print to stdout the memcache packet header.
 * @header: the header to print.
 */
inline void print_memc_header(const MemcHeader &header)
{
    std::ios_base::fmtflags flags = std::cout.flags();
    std::cout << std::hex;

    std::cout << "Memcache Header" << std::endl;
    std::cout << "-   type: 0x" << (uint16_t)header.type << std::endl;
    std::cout << "-    cmd: 0x" << (uint16_t)header.cmd << std::endl;
    std::cout << "-   keyl: 0x" << header.keylen << std::endl;
    std::cout << "-   extl: 0x" << (uint16_t)header.extralen << std::endl;
    std::cout << "-   data: 0x" << (uint16_t)header.datatype << std::endl;
    std::cout << "- status: 0x" << (uint16_t)header.status << std::endl;
    std::cout << "-  bodyl: 0x" << header.bodylen << std::endl;
    std::cout << "- opaque: 0x" << header.opaque << std::endl;
    std::cout << "-   vers: 0x" << header.version << std::endl;

    std::cout.flags(flags);
}

// Memcache stat keys.
const std::string MemcStatTime = "time";
const std::string MemcStatCurrItems = "curr_items";
const std::string MemcStatBytes = "bytes";
const std::string MemcStatBytesRead = "bytes_read";
const std::string MemcStatBytesWritten = "bytes_written";
const std::string MemcStatEvictions = "evictions";
const std::string MemcStatExpirations = "expired";
const std::string MemcStatTotalItems = "total_items";
const std::string MemcStatCurrConnections = "curr_connections";
const std::string MemcStatTotalConnections = "total_connections";
const std::string MemcStatAuthCmds = "auth_cmds";
const std::string MemcStatAuthErrors = "auth_errors";
const std::string MemcStatGet = "cmd_get";
const std::string MemcStatSet = "cmd_set";
const std::string MemcStatDelete = "cmd_delete";
const std::string MemcStatTouch = "cmd_touch";
const std::string MemcStatFlush = "cmd_flush";
const std::string MemcStatGetHits = "get_hits";
const std::string MemcStatGetMisses = "get_misses";
const std::string MemcStatDeleteHits = "delete_hits";
const std::string MemcStatDeleteMisses = "delete_misses";
const std::string MemcStatIncrHits = "incr_hits";
const std::string MemcStatIncrMisses = "incr_misses";
const std::string MemcStatDecrHits = "decr_hits";
const std::string MemcStatDecrMisses = "decr_misses";
const std::string MemcStatTouchHits = "touch_hits";
const std::string MemcStatTouchMisses = "touch_misses";
const std::string MemcStatMemLimit = "limit_maxbytes";
const std::string MemcStatCasHits = "cas_hits";
const std::string MemcStatCasMiss = "cas_misses";
const std::string MemcStatCasBadval = "cas_badval";

// Memcache 'stats settings' keys.
const std::string MemcStatSetMaxBytes = "maxbytes";
const std::string MemcStatSetTcpPORT = "tcpport";
const std::string MemcStatSetCas = "cas_enabled";
const std::string MemcStatSetAuth = "auth_enabled_sasl";
const std::string MemcStatSetMaxItem = "item_size_max";

// Memcache 'stats ites' keys.
const std::string MemcStatItemsSize = "chunk_size";
const std::string MemcStatItemsNum = "number";
const std::string MemcStatItemsEvicted = "evicted";
const std::string MemcStatItemsEvictedNZ = "evicted_nonzero";
const std::string MemcStatItemsOom = "outofmemory";

#endif /* MUTATED_MEMCACHE_HH */
