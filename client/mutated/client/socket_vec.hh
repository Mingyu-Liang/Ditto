#ifndef MUTATED_SOCKET_VEC_HH
#define MUTATED_SOCKET_VEC_HH

/**
 * socket_vec.hh - async socket I/O support. Relies on the user of the socket
 * to provide appropriately sized buffers for all read and write operations.
 */

#include <cstdint>
#include <cstring>
#include <functional>

#include <limits.h>

class Sock;

/**
 * A vector IO operation (data segment).
 */
struct VIO {
    using complete_cb = std::function<void(Sock *, void *, int)>;

    char *buf;
    size_t len;
    void *cb_data;
    complete_cb complete;

    VIO(void)
      : buf{nullptr}
      , len{0}
      , cb_data{nullptr}
      , complete{}
    {
    }

    VIO(char *buf_, size_t len_, void *cb_data_ = nullptr,
        complete_cb complete_ = complete_cb())
      : buf{buf_}
      , len{len_}
      , cb_data{cb_data_}
      , complete{complete_}
    {
    }

    VIO(const VIO &) = default;
    VIO(VIO &&) = default;
    VIO &operator=(const VIO &) = default;
    VIO &operator=(VIO &&) = default;

    ~VIO(void) {}
};

/**
 * Asynchronous socket (TCP only).
 */
class Sock
{
  private:
    /* Maximum number of outstanding vector IO operations */
    static constexpr size_t MAX_SGS = IOV_MAX;

    int ref_cnt_;      /* the reference count */
    int fd_;           /* the file descriptor */
    bool connected_;   /* is the socket connected? */
    bool rx_rdy_;      /* ready to read? */
    bool tx_rdy_;      /* ready to write? */
    size_t rx_nrents_; /* number of RX SGs */
    size_t tx_nrents_; /* number of TX SGs */
    VIO rx_ents_[MAX_SGS];
    VIO tx_ents_[MAX_SGS];

    /* Low-level recv & send*/
    void rx(void);
    void tx(void);

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

    /* Read and write (vector IO support) */
    void read(const VIO &ent);
    void write(const VIO &ent);

    /* Handle epoll events against this socket */
    void run_io(uint32_t events);

    void get(void) noexcept; /* Take a new reference */
    void put(void);          /* Release a reference */
};

#endif /* MUTATED_SOCKET_VEC_HH */
