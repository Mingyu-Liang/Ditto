#ifndef MUTATED_SOCKET_BUF_HH
#define MUTATED_SOCKET_BUF_HH

/**
 * socket_buf.hh - async socket I/O support. A variant that uses circular
 * buffers internally for memory management of the rx and tx queues.
 */

// XXX: If we allocate a Socket on the stack it segfaults due to the buffer
// sizes.

#include <cstdint>
#include <cstring>
#include <functional>
#include <utility>

#include "buffer.hh"
#include "limits.hh"

class Sock;

/**
 * A RX IO operation.
 */
struct IORx {
    using CB = std::function<size_t(Sock *, void *, char *, size_t, char *,
                                    size_t, int)>;

    size_t hdrlen;
    CB hdrcb;
    size_t bodylen;
    CB bodycb;
    void *cbdata;

    IORx(void) noexcept : hdrlen{0},
                          hdrcb{},
                          bodylen{0},
                          bodycb{},
                          cbdata{nullptr}
    {
    }

    IORx(size_t hdrlen_, CB hdrcb_, size_t bodylen_, CB bodycb_,
         void *cbdata_) noexcept : hdrlen{hdrlen_},
                                   hdrcb{hdrcb_},
                                   bodylen{bodylen_},
                                   bodycb{bodycb_},
                                   cbdata{cbdata_}
    {
    }

    IORx(const IORx &) = default;
    IORx &operator=(const IORx &) = default;
    ~IORx(void) noexcept {}
};

/**
 * A TX IO operation.
 */
struct IOTx {
    using CB = std::function<void(Sock *, void *, int)>;

    size_t len;
    CB cb;
    void *cbdata;

    IOTx(void) noexcept : len{0}, cb{}, cbdata{nullptr} {}

    IOTx(size_t len_, CB cb_, void *cbdata_) noexcept : len{len_},
                                                        cb{cb_},
                                                        cbdata{cbdata_}
    {
    }

    IOTx(const IOTx &) = default;
    IOTx &operator=(const IOTx &) = default;
    ~IOTx(void) noexcept {}
};

/**
 * Asynchronous socket (TCP only). Uses circular buffers internally for
 * managing rx and tx queues.
 *
 * NOTE: write operations (write_commit, write, write_emplace) should be
 * followed by a try_tx to try sending the data if the socket is ready. Write
 * operations place data on the tx buffer but don't attempt to transmit.
 */
class Sock
{
  private:
    using rxqueue = buffer<IORx, MAX_OUTSTANDING_REQS>;
    using txqueue = buffer<IOTx, MAX_OUTSTANDING_REQS>;

    int fd_;         /* the file descriptor */
    bool connected_; /* is the socket connected? */
    bool rx_rdy_;    /* ready to read? */
    bool tx_rdy_;    /* ready to write? */

    rxqueue rx_cbs_; /* read queue */
    charbuf rbuf_;   /* read buffer */

    txqueue tx_cbs_; /* write queue */
    charbuf wbuf_;   /* write buffer */
    size_t tx_out_;  /* total tx data waiting to be sent in txcbs queue */

    void rx(void); /* receive handler */
    void tx(void); /* transmit handler */

  public:
    Sock(void) noexcept;
    ~Sock(void) noexcept;

    /* Disable copy and move */
    Sock(const Sock &) = delete;
    Sock(Sock &&) = delete;
    Sock operator=(const Sock &) = delete;
    Sock operator=(Sock &&) = delete;

    /* Access underlying file descriptor */
    int fd(void) const noexcept { return fd_; }

    /* Open a new remote connection */
    void connect(const char *addr, unsigned short port);

    /* Read queueing */
    void read(const IORx &io);

    /* Write queueing preparation */
    std::pair<char *, char *> write_prepare(size_t &len);
    void write_commit(const size_t len);

    /* Write */
    void write(const void *data, const size_t len);

    /* Write by constructing in-place */
    template <class T, class... Args> void write_emplace(Args &&... args)
    {
        std::size_t n = sizeof(T), n1 = n;
        auto p = write_prepare(n1);
        if (p.second == nullptr) {
            ::new (static_cast<void *>(p.first))
              T(std::forward<Args>(args)...);
        } else {
            T t(std::forward<Args>(args)...);
            memcpy(p.first, &t, n1);
            memcpy(p.second, &t + n1, n - n1);
        }
        write_commit(n);
    }

    /* Insert a write callback to fire once all data previously inserted into
     * the queue has been sent. You should insert a callback point _before_
     * calling `try_tx()` ideally. */
    void write_cb_point(const IOTx::CB cb, void *data);

    /* Attempt to transmit data if the socket is ready */
    void try_tx(void);

    /* Handle epoll events against this socket */
    void run_io(uint32_t events);
};

#endif /* MUTATED_SOCKET_BUF_HH */
