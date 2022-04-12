#include <algorithm>
#include <iostream>
#include <system_error>
#include <utility>

#include <arpa/inet.h>
#include <errno.h>
#include <fcntl.h>
#include <netinet/tcp.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>

#include "linux_compat.hh"
#include "socket_buf.hh"
#include "util.hh"

using namespace std;

/**
 * Sock - construct a new socket.
 */
Sock::Sock(void) noexcept : fd_{-1},
                            connected_{false},
                            rx_rdy_{false},
                            tx_rdy_{false},
                            rx_cbs_{},
                            rbuf_{},
                            tx_cbs_{},
                            wbuf_{},
                            tx_out_{0}
{
}

/**
 * ~Sock - deconstruct a socket.
 */
Sock::~Sock(void) noexcept
{
    // cancel all pending read requests
    for (auto &rxcb : rx_cbs_) {
        if (rxcb.hdrcb) {
            rxcb.hdrcb(this, rxcb.cbdata, nullptr, 0, nullptr, 0, -EIO);
        }
        if (rxcb.bodycb) {
            rxcb.bodycb(this, rxcb.cbdata, nullptr, 0, nullptr, 0, -EIO);
        }
    }

    // cancel all pending write requests
    for (auto &txcb : tx_cbs_) {
        if (txcb.cb) {
            txcb.cb(this, txcb.cbdata, -EIO);
        }
    }

    // we don't check for any errors since difficult to handle in a
    // deconstructor
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
    rx_cbs_.clear();
    tx_cbs_.clear();
    tx_out_ = 0;
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
    // run till we block (EAGAIN)
    while (true) {
        // is anything pending for read?
        if (rx_cbs_.items() == 0) {
            return;
        }

        // do the read
        ssize_t nbytes;
        size_t n = rbuf_.space(), n1 = n;
        auto rptrs = rbuf_.queue_prep(n1);
        if (rptrs.second == nullptr) {
            // no wrapping, normal read
            nbytes = ::read(fd_, rptrs.first, n);
        } else {
            // need to wrap, so use writev
            iovec iov[2];
            iov[0].iov_base = rptrs.first;
            iov[0].iov_len = n1;
            iov[1].iov_base = rptrs.second;
            iov[1].iov_len = n - n1;
            nbytes = ::readv(fd_, iov, 2);
        }

        if (nbytes < 0 and errno == EAGAIN) {
            rx_rdy_ = false;
            return;
        } else if (nbytes <= 0) {
            throw system_error(errno, system_category(),
                               "Sock::rx: readv error");
        } else if (size_t(nbytes) > n) {
            throw runtime_error(
              "Sock::rx: read returned more bytes than asked");
        }
        rbuf_.queue_commit(nbytes);

        size_t drop = 0;
        for (auto &rxcb : rx_cbs_) {
            if (rxcb.hdrlen > 0) {
                if (rbuf_.items() < rxcb.hdrlen) {
                    if (!rxcb.hdrcb) { // partial drop when no cb
                        size_t n = rbuf_.items();
                        rxcb.hdrlen -= n;
                        rbuf_.drop(n);
                    }
                    break;
                }
                if (rxcb.hdrcb) {
                    n = n1 = rxcb.hdrlen;
                    rptrs = rbuf_.peek(n1);
                    // parse header and set body length from it
                    rxcb.bodylen = rxcb.hdrcb(this, rxcb.cbdata, rptrs.first,
                                              n1, rptrs.second, n - n1, 0);
                }
                rbuf_.drop(rxcb.hdrlen);
                rxcb.hdrlen = 0; // mark header done
            }

            if (rxcb.bodylen > 0) {
                if (rbuf_.items() < rxcb.bodylen) {
                    if (!rxcb.bodycb) { // partial drop when no cb
                        size_t n = rbuf_.items();
                        rxcb.bodylen -= n;
                        rbuf_.drop(n);
                    }
                    break;
                }
                if (rxcb.bodycb) {
                    n = n1 = rxcb.bodylen;
                    rptrs = rbuf_.peek(n1);
                    rxcb.bodycb(this, rxcb.cbdata, rptrs.first, n1,
                                rptrs.second, n - n1, 0);
                }
                rbuf_.drop(rxcb.bodylen);
                rxcb.bodylen = 0; // mark body done
            }

            drop++;
        }

        // drop done packets
        rx_cbs_.drop(drop);
    }
}

/**
 * read - enqueue data to receive from the socket and read if socket ready.
 * @ent: the scatter-gather entry.
 */
void Sock::read(const IORx &op)
{
    size_t n = 1;
    *rx_cbs_.queue(n) = op;
    if (rx_rdy_) {
        rx();
    }
}

/**
 * tx - push pending writes to the wire.
 */
void Sock::tx(void)
{
    while (true) {
        // is anything pending for send?
        if (wbuf_.items() == 0) {
            return;
        }

        ssize_t nbytes;
        size_t n = wbuf_.items(), n1 = n;
        auto wptrs = wbuf_.peek(n1);

        if (wptrs.second == nullptr) {
            // no wrapping, normal write
            nbytes = ::write(fd_, wptrs.first, n);
        } else {
            // need to wrap, so use writev
            iovec iov[2];
            iov[0].iov_base = wptrs.first;
            iov[0].iov_len = n1;
            iov[1].iov_base = wptrs.second;
            iov[1].iov_len = n - n1;
            nbytes = ::writev(fd_, iov, 2);
        }

        if (nbytes < 0) {
            if (errno == EAGAIN) {
                tx_rdy_ = false;
                return;
            } else {
                throw system_error(errno, system_category(),
                                   "Sock::tx: write error");
            }
        } else if (size_t(nbytes) > n) {
            throw runtime_error("Sock::tx: write sent more bytes than asked");
        }
        wbuf_.drop(nbytes);

        // update tx callbacks
        size_t drop = 0;
        for (auto &txcb : tx_cbs_) {
            if (txcb.len > size_t(nbytes)) {
                txcb.len -= nbytes;
                tx_out_ -= nbytes;
                break;
            } else {
                txcb.cb(this, txcb.cbdata, 0);
                nbytes -= txcb.len;
                tx_out_ -= txcb.len;
                drop++;
            }
        }
        tx_cbs_.drop(drop);
    }
}

/**
 * Prepare a write on this socket.
 * @len: the size of the requested write. The available buffer through the
 * first pointer is returned through len.
 * @return: the buffer, split between two contiguous segments, for the write.
 * The length of the first segment is returned through len, the length of the
 * second segment is the remaining needed buffer to fullfill the request.
 */
pair<char *, char *> Sock::write_prepare(size_t &len)
{
    return wbuf_.queue_prep(len);
}

/**
 * Commit a previously prepared write on this socket, making it available for
 * transmission.
 * @len: the length of previously prepared write to commit.
 */
void Sock::write_commit(const size_t len) { wbuf_.queue_commit(len); }

/**
 * Copy len bytes from data to the socket tx queue for transmission.
 * @data: data to copy to the tx queue.
 * @len: length of bytes to copy from data.
 */
void Sock::write(const void *data, const size_t len)
{
    const char *p = reinterpret_cast<const char *>(data);
    size_t n1 = len;
    auto wptrs = write_prepare(n1);
    memcpy(wptrs.first, p, n1);
    if (n1 != len) {
        memcpy(wptrs.second, p + n1, len - n1);
    }
    write_commit(len);
}

/**
 * Insert a write callback to fire once all data previously inserted into the
 * queue has been sent. You should insert a callback point _before_ calling
 * `try_tx()` ideally.
 * @cb: the write callback to fire.
 * @data: the callback data.
 */
void Sock::write_cb_point(const IOTx::CB cb, void *data)
{
    // we want to store CB's by bytes needing to be sent as a delta from the
    // earlier CB as it makes firing them more efficient.
    size_t len = wbuf_.items();
    if (tx_cbs_.items() == 0) {
        tx_cbs_.queue_emplace(len, cb, data);
    } else {
        tx_cbs_.queue_emplace(len - tx_out_, cb, data);
    }
    tx_out_ = len;
}

/**
 * Commit a previously prepared write on this socket, making it available for
 * transmission.
 * @len: the length of previously prepared write to commit.
 */
void Sock::try_tx(void)
{
    if (tx_rdy_) {
        tx();
    }
}

/**
 * __socket_check_connected - check if their is a socket error on the file.
 * @fd: the file descriptor to check for a socket error.
 * @return: throws the error if present.
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
}
