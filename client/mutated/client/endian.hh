#ifndef MUTATED_ENDIAN_HH
#define MUTATED_ENDIAN_HH

/**
 * endian.hh - abstract platform differences for endian transformation
 * functions.
 */

#if defined(__APPLE__)
#include <machine/endian.h>

#elif defined(__linux__)
#include <arpa/inet.h>
#include <endian.h>
#include <cstdint>

inline uint64_t htonll(uint64_t host) { return htobe64(host); }
inline uint64_t ntohll(uint64_t netw) { return be64toh(netw); }

#else /* BSDs */
#include <arpa/inet.h>
#include <cstdint>
#include <sys/endian.h>
#include <sys/types.h>

inline uint64_t htonll(uint64_t host) { return htobe64(host); }
inline uint64_t ntohll(uint64_t netw) { return be64toh(netw); }
#endif

#endif /* MUTATED_ENDIAN_HH */
