#ifndef UTILS_H
#define UTILS_H

#include <cstdint>

class TCPConn;

const int MAX_FD = 65536;          
const int MAX_EVENT_NUMBER = 10000;       

int setnonblocking(int fd);

void addfd(int epollfd, int fd, bool et);

void removefd(int epollfd, int fd);

void modfd(int epollfd, int fd, int ev);

void handleNetwork(int connfd, TCPConn* conn, uint64_t* shared_pointer_chasing_mem_data);

void handleNewConn(TCPConn* conns, int listen_fd, uint64_t* shared_pointer_chasing_mem_data, int epoll_fd = -1);

void runAssembly(uint64_t* mem_data, uint64_t req_id, uint64_t* curr_mem_addrs, uint64_t* curr_pointer_chasing_mem_addrs);

#endif