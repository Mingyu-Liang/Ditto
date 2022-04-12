#ifndef MUTATED_UTILS_HH
#define MUTATED_UTILS_HH

/**
 * util.hh - various odds & ends, helper utilities.
 */

#include <string>
#include <system_error>

/* Nanoseconds in a second. */
static constexpr double NSEC = 1000000000;

#define UNUSED(x) ((void)(x))

inline unsigned int system_call(int status, const char *fail, int code = 0)
{
    if (status < 0) {
        code = code == 0 ? errno : code;
        throw std::system_error(code, std::system_category(), fail);
    } else {
        return status;
    }
}

inline unsigned int system_call(int status, std::string fail, int code = 0)
{
    return system_call(status, fail.c_str(), code);
}

#endif /* MUTATED_UTILS_HH */
