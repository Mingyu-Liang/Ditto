#ifndef SERVICE_H
#define SERVICE_H

#include <arpa/inet.h>
#include <errno.h>
#include <netinet/in.h>
#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <sys/epoll.h>
#include <sys/socket.h>
#include <unistd.h>

#include "./connection/tcp_conn.h"
#include "./threadpool/threadpool.h"
#include "./utils.h"

class Service
{
public:
    Service();
    ~Service();

    void Init(int port, int network_thread_number, int accept_thread_number);
    void EventListen();
    void EventLoop();

public:
    int service_port_;
    int epoll_fd_;
    TCPConn* conns_;

    EpollAcceptThreadPool* epoll_accept_thread_pool_;
    EpollNetworkThreadPool* epoll_network_thread_pool_;
    int network_thread_number_;
    int* network_epoll_fds_;
    int accept_thread_number_;
    int listen_fd_;

    uint64_t* shared_pointer_chasing_mem_data_;
};

#endif