#ifndef THREADPOOL_H
#define THREADPOOL_H

#include <cstdio>
#include <cstring>
#include <errno.h>
#include <exception>
#include <iostream>
#include <list>
#include <mutex>
#include <pthread.h>
#include <stdexcept>
#include <vector>

#include "../connection/tcp_conn.h"
#include "../lock/locker.h"
#include "../utils.h"

using namespace std;

class EpollNetworkThread
{
public:
    TCPConn* conns_;
    int epoll_fd_ = -1;
    int* epoll_fds_;
    int thread_id_;
    uint64_t* shared_pointer_chasing_mem_data_;

    EpollNetworkThread(TCPConn* conns, int thread_id, int* epoll_fds, uint64_t* shared_pointer_chasing_mem_data)
    {
        conns_ = conns;
        epoll_fds_ = epoll_fds;
        thread_id_ = thread_id;
        shared_pointer_chasing_mem_data_ = shared_pointer_chasing_mem_data;
    };

    static void *Work(void *args)
    {
        EpollNetworkThread* network_thread = (EpollNetworkThread*)args;
        network_thread->Run();
        return network_thread;
    }

    void Run()
    {
        epoll_event events[MAX_EVENT_NUMBER];
        epoll_fd_ = epoll_create(5);
        assert(epoll_fd_ != -1);
        epoll_fds_[thread_id_] = epoll_fd_;

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

        bool stop = false;
        while (!stop)
        {
            int number = epoll_wait(epoll_fd_, events, MAX_EVENT_NUMBER, -1);
            if (number < 0 && errno != EINTR)
            {
                printf("%s", "Network thread epoll fails.");
                break;
            }

            for (int i = 0; i < number; i++)
            {
                int socket_fd = events[i].data.fd;
                if (events[i].events & (EPOLLRDHUP | EPOLLHUP | EPOLLERR))
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
            }
        }
    }
    ~EpollNetworkThread(){};
};

class EpollNetworkThreadPool
{
public:
    pthread_t* threads_;
    vector<EpollNetworkThread> epoll_network_threads_;

    EpollNetworkThreadPool(TCPConn* conns, int* epoll_fds, int network_thread_number, uint64_t* shared_pointer_chasing_mem_data)
    {
        if (network_thread_number <= 0)
            throw std::exception();
        threads_ = new pthread_t[network_thread_number];

        for (int i = 0; i < network_thread_number; ++i)
        {
            epoll_network_threads_.push_back(EpollNetworkThread(conns, i, epoll_fds, shared_pointer_chasing_mem_data));
        }

        if (!threads_)
            throw std::exception();
        for (int i = 0; i < network_thread_number; ++i)
        {
            pthread_create(threads_ + i, NULL, EpollNetworkThread::Work, &epoll_network_threads_[i]);
            pthread_detach(threads_[i]);
        }
    }
    ~EpollNetworkThreadPool()
    {
        delete[] threads_;
        vector<EpollNetworkThread>().swap(epoll_network_threads_);
    }
};

class EpollAcceptThread
{
public:
    TCPConn* conns_;
    int thread_id_;
    int listen_fd_;
    int port_;
    int* network_epoll_fds_;
    int network_thread_number_;
    uint64_t* shared_pointer_chasing_mem_data_;

    EpollAcceptThread(TCPConn* conns, int thread_id, int port, int* network_epoll_fds, int network_thread_number, uint64_t* shared_pointer_chasing_mem_data)
    {
        conns_ = conns;
        thread_id_ = thread_id;
        port_ = port;
        network_epoll_fds_ = network_epoll_fds;
        network_thread_number_ = network_thread_number;
        shared_pointer_chasing_mem_data_ = shared_pointer_chasing_mem_data;
    };

    static void *Work(void *args)
    {
        EpollAcceptThread* accept_thread = (EpollAcceptThread*)args;
        accept_thread->Run();
        return accept_thread;
    }

    void Run()
    {
        int listen_fd_ = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
        assert(listen_fd_ >= 0);
        struct sockaddr_in address;
        bzero(&address, sizeof(address));
        address.sin_family = AF_INET;
        address.sin_addr.s_addr = htonl(INADDR_ANY);
        address.sin_port = htons(port_);

        int reuse_flag = 1;
        int ret = setsockopt(listen_fd_, SOL_SOCKET, SO_REUSEPORT, &reuse_flag, sizeof(reuse_flag));
        if (ret < 0) {
            printf("Accept thread setsocketopt error: %s\n", strerror(errno));
        }
        ret = bind(listen_fd_, (struct sockaddr *)&address, sizeof(address));
        if (ret < 0) {
            printf("Accept thread bind error: %s\n", strerror(errno));
        }
        ret = listen(listen_fd_, 5);
        if (ret < 0) {
            printf("Accept thread listen error: %s\n", strerror(errno));
        }
        
        epoll_event events[MAX_EVENT_NUMBER];
        int accept_epoll_fd_ = epoll_create(5);
        assert(accept_epoll_fd_ != -1);
        addfd(accept_epoll_fd_, listen_fd_, false);

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
        bool stop = false;
        while (!stop)
        {
            int number = epoll_wait(accept_epoll_fd_, events, MAX_EVENT_NUMBER, -1);
            if (number < 0 && errno != EINTR)
            {
                printf("%s", "Accept thread epoll fails.");
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
                    handleNewConn(conns_, listen_fd_, shared_pointer_chasing_mem_data_, accept_epoll_fd_);
                }
                else if (events[i].events & (EPOLLRDHUP | EPOLLHUP | EPOLLERR))
                {
                    epoll_ctl(accept_epoll_fd_, EPOLL_CTL_DEL, socket_fd, 0);
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
    }
    ~EpollAcceptThread(){};
};

class EpollAcceptThreadPool
{
public:
    pthread_t* threads_;
    vector<EpollAcceptThread> epoll_accept_threads_;

    EpollAcceptThreadPool(TCPConn* conns, int accept_thread_number, int port, int* network_epoll_fds, int network_thread_number, uint64_t* shared_pointer_chasing_mem_data)
    {
        if (accept_thread_number <= 0)
            throw std::exception();
        threads_ = new pthread_t[accept_thread_number];

        for (int i = 0; i < accept_thread_number; ++i)
        {
            epoll_accept_threads_.push_back(EpollAcceptThread(conns, i, port, network_epoll_fds, network_thread_number, shared_pointer_chasing_mem_data));
        }

        if (!threads_)
            throw std::exception();
        for (int i = 0; i < accept_thread_number; ++i)
        {
            pthread_create(threads_ + i, NULL, EpollAcceptThread::Work, &epoll_accept_threads_[i]);
            pthread_detach(threads_[i]);
        }
    }
    ~EpollAcceptThreadPool()
    {
        delete[] threads_;
        vector<EpollAcceptThread>().swap(epoll_accept_threads_);
    }
};

#endif
