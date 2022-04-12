#include <algorithm>
#include <system_error>

#include <arpa/inet.h>
#include <errno.h>
#include <fcntl.h>
#include <netinet/tcp.h>
#include <sys/epoll.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>

#include "socket_vec.hh"
#include "util.hh"

using namespace std;

/**
 * Sock - construct a new socket.
 */
Sock::Sock(void) noexcept : ref_cnt_{1},
                            fd_{-1},
                            connected_{false},
                            rx_rdy_{false},
                            tx_rdy_{false},
                            rx_nrents_{0},
                            tx_nrents_{0}
{
}

/**
 * ~Sock - deconstruct a socket.
 */
Sock::~Sock(void) noexcept
{
    for (size_t i = 0; i < rx_nrents_; i++) {
        if (rx_ents_[i].complete) {
            rx_ents_[i].complete(this, rx_ents_[i].cb_data, -EIO);
        }
    }

    for (size_t i = 0; i < tx_nrents_; i++) {
        if (tx_ents_[i].complete) {
            tx_ents_[i].complete(this, tx_ents_[i].cb_data, -EIO);
        }
    }

    if (fd_ >= 0) {
        // Explicitly send a FIN
        shutdown(fd_, SHUT_RDWR);

        // Turn on (zero-length) linger to avoid running out of ports by
        // sending a RST when we close the file descriptor.
        //
        // ezyang: see my writeup at http://stackoverflow.com/a/28377819/23845
        // for details.
        linger linger;
        linger.l_onoff = 1;
        linger.l_linger = 0;
        setsockopt(fd_, SOL_SOCKET, SO_LINGER, (char *)&linger,
                   sizeof(linger));
        close(fd_);
    }

    fd_ = -1;
    connected_ = false;
    rx_rdy_ = false;
    tx_rdy_ = false;
    rx_nrents_ = 0;
    tx_nrents_ = 0;
}

/**
 * get - increase the reference count.
 */
void Sock::get(void) noexcept { ref_cnt_++; }

/**
 * set - decrease the reference count, will deallocate if hits zero.
 */
void Sock::put(void)
{
    if (--ref_cnt_ == 0) {
        delete this;
    } else if (ref_cnt_ < 0) {
        throw std::runtime_error("sock::put refcnt < 0");
    }
}

/**
 * connect - establishes an outgoing TCP connection.
 * @addr: the IPv4 address.
 * @port: the destination port.
 *
 * NOTE: disables nagle and makes the socket nonblocking.
 */
void Sock::connect(const char *addr, unsigned short port)
{
    int ret, opts;
    sockaddr_in saddr;

    fd_ =
      system_call(socket(AF_INET, SOCK_STREAM, 0), "Sock::connect: socket()");

    // make the socket nonblocking
    opts = system_call(fcntl(fd_, F_GETFL), "Sock::connect: fcntl(F_GETFL)");
    opts = (opts | O_NONBLOCK);
    system_call(fcntl(fd_, F_SETFL, opts), "Sock::connect: fcntl(F_SETFL)");

    // connect
    memset(&saddr, 0, sizeof(saddr));
    saddr.sin_family = AF_INET;
    saddr.sin_addr.s_addr = inet_addr(addr);
    saddr.sin_port = htons(port);

    ret = ::connect(fd_, (sockaddr *)&saddr, sizeof(saddr));
    if (ret == -1 and errno != EINPROGRESS) {
        throw system_error(errno, system_category(),
                           "Sock::connect: connect()");
    }

    // disable TCP nagle algorithm (for lower latency)
    opts = 1;
    system_call(
      setsockopt(fd_, IPPROTO_TCP, TCP_NODELAY, (char *)&opts, sizeof(int)),
      "Sock::connect: setsockopt(TCP_NODELAY)");
}

/**
 * rx - receive segments from the wire.
 */
void Sock::rx(void)
{
    // is anything pending for read?
    if (rx_nrents_ == 0) {
        return;
    }

    // prepare io read vector
    iovec *iov = (iovec *)alloca(sizeof(iovec) * rx_nrents_);
    for (size_t i = 0; i < rx_nrents_; i++) {
        iov[i].iov_base = rx_ents_[i].buf;
        iov[i].iov_len = rx_ents_[i].len;
    }

    // read io vector from wire
    ssize_t ret = readv(fd_, iov, rx_nrents_);
    if (ret < 0 and errno == EAGAIN) {
        rx_rdy_ = false;
        return;
    } else if (ret <= 0) {
        throw system_error(errno, system_category(), "Sock::rx: readv error");
    }

    // update outstanding IO given bytes read
    get();
    for (size_t i = 0; i < rx_nrents_; i++) {
        if ((size_t)ret < rx_ents_[i].len) {
            // partial read
            rx_ents_[i].len -= ret;
            rx_ents_[i].buf += ret;

            move(rx_ents_ + i, rx_ents_ + rx_nrents_, rx_ents_);
            rx_nrents_ -= i;
            put();

            return;
        }

        // full read, invoke callback
        if (rx_ents_[i].complete) {
            rx_ents_[i].complete(this, rx_ents_[i].cb_data, 0);
        }
        ret -= rx_ents_[i].len;
    }

    if (ret != 0) {
        throw runtime_error("Sock::rx: readv returned more bytes than asked");
    }
    rx_nrents_ = 0;
    put();
}

/**
 * read - enqueue data to receive from the socket and read if socket ready.
 * @ent: the scatter-gather entry.
 */
void Sock::read(const VIO &ent)
{
    if (rx_nrents_ >= MAX_SGS) {
        throw system_error(ENOSPC, system_category(),
                           "Sock::read: too many segments");
    }
    rx_ents_[rx_nrents_++] = ent;

    if (rx_rdy_) {
        rx();
    }
}

/**
 * tx - push pending writes to the wire.
 */
void Sock::tx(void)
{
    // is anything pending for send?
    if (tx_nrents_ == 0) {
        return;
    }

    // prepare io write vector
    iovec *iov = (iovec *)alloca(sizeof(iovec) * tx_nrents_);
    for (size_t i = 0; i < tx_nrents_; i++) {
        iov[i].iov_base = tx_ents_[i].buf;
        iov[i].iov_len = tx_ents_[i].len;
    }

    // write io vector to wire
    ssize_t nbytes = writev(fd_, iov, tx_nrents_);
    if (nbytes < 0) {
        if (errno == EAGAIN) {
            tx_rdy_ = false;
            return;
        } else {
            throw system_error(errno, system_category(),
                               "Sock::tx: writev error");
        }
    }

    // update outstanding IO given bytes written
    get();
    for (size_t i = 0; i < tx_nrents_; i++) {
        if ((size_t)nbytes < tx_ents_[i].len) {
            // partial write
            tx_ents_[i].len -= nbytes;
            tx_ents_[i].buf += nbytes;

            move(tx_ents_ + i, tx_ents_ + tx_nrents_, tx_ents_);
            tx_nrents_ -= i;
            put();

            return;
        }

        // full write, invoke callback
        if (tx_ents_[i].complete) {
            tx_ents_[i].complete(this, tx_ents_[i].cb_data, 0);
        }
        nbytes -= tx_ents_[i].len;
    }

    if (nbytes != 0) {
        throw runtime_error("Sock::tx: writev returned more bytes than asked");
    }
    tx_nrents_ = 0;
    put();
}

/**
 * write - enqueue data to send on the socket and send if socket ready.
 * @ent: the scatter-gather entry.
 */
void Sock::write(const VIO &ent)
{
    if (tx_nrents_ >= MAX_SGS) {
        throw system_error(ENOSPC, system_category(),
                           "Sock::write: too many segments");
    }
    tx_ents_[tx_nrents_++] = ent;

    if (tx_rdy_) {
        tx();
    }
}

/**
 * __socket_check_connected - check if their is a socket error on the file.
 * @fd: the file descriptor to check for a socket error.
 * @return: throws the exception if present.
 */
static void __socket_check_connected(int fd)
{
    int valopt;
    socklen_t len = sizeof(int);

    if (getsockopt(fd, SOL_SOCKET, SO_ERROR, (void *)&valopt, &len)) {
        throw system_error(errno, system_category(),
                           "Sock::__socket_get_connect_error: getsockopt()");
    } else if (valopt) {
        throw system_error(valopt, system_category(),
                           "Sock::run_io: socket failed to connect");
    }
}

/**
 * run_io - handle an epoll event against the socket.
 * @events: the bitmask of epoll events that occured.
 */
void Sock::run_io(uint32_t events)
{
    get();

    if (events & EPOLLIN) {
        rx_rdy_ = true;
        rx();
    }

    if (events & EPOLLOUT) {
        if (not connected_) {
            __socket_check_connected(fd_);
            connected_ = true;
        }
        tx_rdy_ = true;
        tx();
    }

    put();
}
