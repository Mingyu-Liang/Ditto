#include "service.h"
#include <netinet/tcp.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>
#include <netinet/in.h>

#include <string>
#include <iostream>
#include <vector>
#include <random>       
#include <chrono>
#include <numeric>
#include <algorithm>
#include <thread>

using namespace std;

Service::Service()
{
    conns_ = new TCPConn[MAX_FD];
}

Service::~Service()
{
    close(epoll_fd_);
    close(listen_fd_);
    delete[] conns_;
    delete epoll_network_thread_pool_;
    delete epoll_accept_thread_pool_;
}

void Service::Init(int port, int network_thread_number, int accept_thread_number)
{
    service_port_ = port;
    network_thread_number_ = network_thread_number;
    accept_thread_number_ = accept_thread_number;
    network_epoll_fds_ = new int[network_thread_number_];

    uint64_t cache_init_size = 64;
    uint64_t cache_max_size = 256*1024*1024;
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    shared_pointer_chasing_mem_data_ = new uint64_t[cache_max_size / 8];
    uint64_t begin = 0;
    for (uint64_t i = 0; i < 23; i++) {
        uint64_t end = (cache_init_size << i) / 8;
        std::vector<int> x(end - begin);
        std::iota(std::begin(x), std::end(x), begin); 
        shuffle(x.begin(), x.end(), std::default_random_engine(seed));
        for (uint64_t j = begin; j < end; j++) {
            shared_pointer_chasing_mem_data_[j] = (uint64_t) &shared_pointer_chasing_mem_data_[x[j - begin]];
        }
        begin = end;
    }
}

void Service::EventListen()
{
#ifdef NETWORKDISPATCH
#ifdef NETWORKEPOLL
    epoll_network_thread_pool_ = new EpollNetworkThreadPool(conns_, network_epoll_fds_, network_thread_number_, shared_pointer_chasing_mem_data_);
#endif // NETWORKEPOLL
#endif // NETWORKDISPATCH
#ifdef ACCEPTDISPATCH
    epoll_accept_thread_pool_ = new EpollAcceptThreadPool(conns_, accept_thread_number_, service_port_, network_epoll_fds_, network_thread_number_);
#else
    listen_fd_ = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    assert(listen_fd_ >= 0);

    struct sockaddr_in address;
    bzero(&address, sizeof(address));
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = htonl(INADDR_ANY);
    address.sin_port = htons(service_port_);

    int reuse_flag = 1;
	int ret = setsockopt(listen_fd_, SOL_SOCKET, SO_REUSEPORT, &reuse_flag, sizeof(reuse_flag));
    if (ret < 0) {
        printf("Main thread setsocketopt error: %s\n", strerror(errno));
    }
    ret = bind(listen_fd_, (struct sockaddr *)&address, sizeof(address));
    if (ret < 0) {
        printf("Main thread bind error: %s\n", strerror(errno));
    }
    ret = listen(listen_fd_, 5);
    if (ret < 0) {
        printf("Main thread listen error: %s\n", strerror(errno));
    }

    epoll_fd_ = epoll_create(5);
    assert(epoll_fd_ != -1);
    addfd(epoll_fd_, listen_fd_, false);
#endif // ACCEPTDISPATCH
}

void Service::EventLoop()
{
#ifdef ACCEPTDISPATCH
    while (true) {
        sleep(1000000);
    }
#else
#ifndef NETWORKDISPATCH
    uint64_t mem_size =256*1024*1024;
    uint64_t* mem_data = new uint64_t[mem_size / 8];
    uint64_t* curr_mem_addrs = new uint64_t[23];
    uint64_t* curr_pointer_chasing_mem_addrs = new uint64_t[23];
    uint64_t curr_idx = 0;
    for (int i = 0; i < 23; i++) {
        curr_mem_addrs[i] = (uint64_t) &mem_data[curr_idx];
        curr_pointer_chasing_mem_addrs[i] = (uint64_t) &shared_pointer_chasing_mem_data_[curr_idx];
        curr_idx = (64 << i) / 8;
    }
    uint64_t request_id = 0;
#endif // NETWORKDISPATCH

    int network_turn = 0;
    epoll_event events[MAX_EVENT_NUMBER];

    while (true)
    {
        int number = epoll_wait(epoll_fd_, events, MAX_EVENT_NUMBER, -1);

        if (number < 0 && errno != EINTR)
        {
            printf("%s\n", "Main thread epoll fails.");
            break;
        }

        for (int i = 0; i < number; i++)
        {
            int socket_fd = events[i].data.fd;
            if (socket_fd == listen_fd_)
            {
#ifdef NETWORKDISPATCH
#ifdef NETWORKEPOLL
                // Use round-robin to dispatch to network threads.
                int network_epoll_fd = network_epoll_fds_[network_turn++];
                if (network_turn == network_thread_number_) network_turn = 0;
                handleNewConn(conns_, listen_fd_, shared_pointer_chasing_mem_data_, network_epoll_fd);
#else
                handleNewConn(conns_, listen_fd_, shared_pointer_chasing_mem_data_);
#endif // NETWORKEPOLL
            }
#else
                handleNewConn(conns_, listen_fd_, shared_pointer_chasing_mem_data_, epoll_fd_);
            }
            else if (events[i].events & (EPOLLRDHUP | EPOLLHUP | EPOLLERR))
            {
                epoll_ctl(epoll_fd_, EPOLL_CTL_DEL, socket_fd, 0);
                close(socket_fd);
            }
            else if (events[i].events & EPOLLIN)
            {
                TCPConn* conn = conns_ + socket_fd;
                if(conn->ReadOnce())
                {
                    conn->Process(mem_data, curr_mem_addrs, curr_pointer_chasing_mem_addrs, request_id);
                }
            }
#endif // NETWORKDISPATCH
        }
    }
#endif // ACCEPTDISPATCH
}