#ifndef MUTATED_LIMITS_HH
#define MUTATED_LIMITS_HH

/**
 * limits.hh - pull some buffer/queue sizes into one place for easy updating.
 */

#include <cstdint>

/* Maximum number of outstanding read IO operations */
constexpr std::size_t MAX_OUTSTANDING_REQS = 1000000;

/* Size of the TX & RX buffers */
constexpr std::size_t CHARBUF_SIZE = 200 * 1024 * 1024;

#endif /* MUTATED_LIMITS_HH */
