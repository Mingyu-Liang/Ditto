#ifndef MUTATED_LINUX_COMPAT_HH
#define MUTATED_LINUX_COMPAT_HH

#if defined(__linux__)

#include <sys/epoll.h>
#include <sys/timerfd.h>
#include <sys/syscall.h>
#include <unistd.h>

/**
 * A syscall implemented on the Shinjuku OS. We don't call on Linux.
 */
static inline int epoll_spin(int epfd, struct epoll_event *events,
                             int maxevents, int timeout)
{
    return (int)syscall(321, epfd, events, maxevents, timeout);
}

#else /* !linux */

#include <stdexcept>

#include <sys/syscall.h>
#include <unistd.h>

#define CLOCK_MONOTONIC 0
#define EPOLLIN 0
#define EPOLLOUT 1
#define EPOLLET 2
#define EPOLL_CTL_ADD 3

struct epoll_data {
    void *ptr;
};

struct epoll_event {
    int events;
    epoll_data data;
};

struct itimerspec {
    timespec it_interval;
    timespec it_value;
};

/**
 * A syscall implemented on the Shinjuku OS. We don't call on Linux.
 */
static inline int epoll_spin(int, struct epoll_event *, int, int)
{
    throw std::runtime_error("epoll_spin not supported");
}

static inline int epoll_wait(int, struct epoll_event *, int, int)
{
    throw std::runtime_error("epoll_wait not supported");
}

static inline int epoll_create1(int)
{
    throw std::runtime_error("epoll_create1 not supported");
}

static inline int timerfd_create(int, int)
{
    throw std::runtime_error("timerfd_create not supported");
}

static inline int epoll_ctl(int, int, int, epoll_event *)
{
    throw std::runtime_error("epoll_ctl not supported");
}

static inline int timerfd_settime(int, int, itimerspec *, void *)
{
    throw std::runtime_error("timerfd_settime not supported");
}

#endif /* !linux */

#endif /* MUTATED_LINUX_COMPAT_HH */
