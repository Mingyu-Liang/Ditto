#ifndef TCPCONN_H
#define TCPCONN_H

#include <assert.h>
#include <errno.h>
#include <fcntl.h>
#include <stdarg.h>
#include <stdio.h>
#include <string.h>
#include <sys/epoll.h>
#include <sys/socket.h>
#include <sys/uio.h>
#include <unistd.h>

class TCPConn
{
public:
    static const int READ_BUFFER_SIZE = 540;
    static const int WRITE_BUFFER_SIZE = 540;

public:
    TCPConn() {}
    ~TCPConn() {}

public:
    void Init(int epoll_fd, int socket_fd);
    void CloseConn(bool real_close = true);
    void Process(uint64_t* mem_data, uint64_t* curr_mem_addrs, uint64_t* curr_pointer_chasing_mem_addrs, uint64_t &request_id);
    bool ReadOnce();
    void WriteOnce();
    int ParseMultiRequest();

private:
    void Reset();

public:
    int epoll_fd_;

private:
    int socket_fd_;
    char read_buf_[READ_BUFFER_SIZE];
    int read_idx_;
    char write_buf_[WRITE_BUFFER_SIZE];
    int write_idx_;
    struct iovec iv_[3];
    int iv_count_;
    int bytes_to_send_;
    int bytes_have_send_;
};

#endif