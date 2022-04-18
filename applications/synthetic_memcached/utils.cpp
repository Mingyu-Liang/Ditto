#include "utils.h"

#include <fcntl.h>
#include <sys/epoll.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netinet/tcp.h>
#include <thread>

#include "connection/tcp_conn.h"
#include "threadpool/threadpool.h"

int setnonblocking(int fd)
{
    int old_option = fcntl(fd, F_GETFL);
    int new_option = old_option | O_NONBLOCK;
    fcntl(fd, F_SETFL, new_option);
    return old_option;
}

void addfd(int epollfd, int fd, bool et)
{
    epoll_event event;
    event.data.fd = fd;
    event.events = EPOLLIN | EPOLLRDHUP;
    if (et)
        event.events |= EPOLLET;
    epoll_ctl(epollfd, EPOLL_CTL_ADD, fd, &event);
}

void removefd(int epollfd, int fd)
{
    epoll_ctl(epollfd, EPOLL_CTL_DEL, fd, 0);
    close(fd);
}

void modfd(int epollfd, int fd, int ev)
{
    epoll_event event;
    event.data.fd = fd;
    event.events = ev | EPOLLONESHOT | EPOLLRDHUP;
    epoll_ctl(epollfd, EPOLL_CTL_MOD, fd, &event);
}

void handleNetwork(int connfd, TCPConn* conn, uint64_t* shared_pointer_chasing_mem_data)
{
    uint64_t mem_size =256*1024*1024;
    uint64_t* mem_data = new uint64_t[mem_size / 8];
    uint64_t* curr_mem_addrs = new uint64_t[23];
    uint64_t* curr_pointer_chasing_mem_addrs = new uint64_t[23];
    uint64_t curr_idx = 0;
    for (int i = 0; i < 23; i++) {
        curr_mem_addrs[i] = (uint64_t) &mem_data[curr_idx];
        curr_pointer_chasing_mem_addrs[i] = (uint64_t) &shared_pointer_chasing_mem_data[curr_idx];
        curr_idx = (64 << i) / 8;
    }
    uint64_t request_id = 0;

    for(;;) {
        if(conn->ReadOnce()) conn->Process(mem_data, curr_mem_addrs, curr_pointer_chasing_mem_addrs, request_id);
        else break;
    }
    close(connfd);
    delete[] mem_data;
}

void handleNewConn(TCPConn* conns, int listen_fd, uint64_t* shared_pointer_chasing_mem_data, int epoll_fd)
{
    struct sockaddr_in client_address;
    socklen_t client_addrlength = sizeof(client_address);

    int connfd = accept(listen_fd, (struct sockaddr *)&client_address, &client_addrlength);
    int flag = 1;
    setsockopt(connfd, IPPROTO_TCP, TCP_NODELAY, (char *) &flag, sizeof(int));
    if (connfd < 0)
    {
        printf("Accept error is: %s.", strerror(errno));
        return;
    }
    conns[connfd].Init(epoll_fd, connfd);

#if defined(BLOCKING) || defined(NONBLOCKING) // Same as #ifndef NETWORKEPOLL
    thread spawned_thread = thread(&handleNetwork, connfd, conns + connfd, shared_pointer_chasing_mem_data);
    spawned_thread.detach();
#endif // BLOCKING || NONBLOCKING
}