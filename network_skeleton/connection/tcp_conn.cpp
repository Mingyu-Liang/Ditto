#include "tcp_conn.h"

#include <sys/stat.h>
#include <sys/time.h>
#include <cstring>
#include <string>

#include "../utils.h"

using namespace std;

// Close a connection.
void TCPConn::CloseConn(bool real_close)
{
    if (real_close && (socket_fd_ != -1))
    {
#ifdef NETWORKEPOLL
        removefd(epoll_fd_, socket_fd_);
#endif // NETWORKEPOLL
        socket_fd_ = -1;
    }
}

// Resetialize a connection and register the sockfd to the epollfd monitored by the network thread assigned to this connection.
void TCPConn::Init(int epoll_fd, int socket_fd)
{
    epoll_fd_ = epoll_fd;
    socket_fd_ = socket_fd;

#ifdef NETWORKEPOLL
    addfd(epoll_fd_, socket_fd_, false);
    setnonblocking(socket_fd_);
#endif // NETWORKEPOLL

#ifdef NONBLOCKING
    setnonblocking(socket_fd_);
#endif // NONBLOCKING

    Reset();
}

// Reset for handling new requests.
void TCPConn::Reset()
{
    bytes_to_send_ = 0;
    bytes_have_send_ = 0;
    read_idx_ = 0;
    write_idx_ = 0;

    memset(read_buf_, '\0', READ_BUFFER_SIZE);
    memset(write_buf_, '\0', WRITE_BUFFER_SIZE);
}

// Read data from socket until no available data or the socket is closed.
bool TCPConn::ReadOnce()
{
    int bytes_read = 0;

#ifdef NETWORKEPOLL
    bytes_read = read(socket_fd_, read_buf_ + read_idx_, READ_BUFFER_SIZE - read_idx_);
#endif // NETWORKEPOLL

#ifdef NONBLOCKING
    while(true) 
    {
        bytes_read = read(socket_fd_, read_buf_ + read_idx_, READ_BUFFER_SIZE - read_idx_);
        if (bytes_read < 0) {
            if (errno == EAGAIN || errno == EWOULDBLOCK) continue;
            else return false;
        }
        else break;
    }
#endif // NONBLOCKING

#ifdef BLOCKING
    bytes_read = read(socket_fd_, read_buf_ + read_idx_, READ_BUFFER_SIZE - read_idx_);
#endif // BLOCKING

    read_idx_ += bytes_read;
    if (bytes_read <= 0) {
        return false;
    }
    return true;
}

// Write reponse to socket.
void TCPConn::WriteOnce()
{
#if defined(NETWORKEPOLL) || defined(NONBLOCKING)
    while (true)
    {
        int temp = 0;
        temp = writev(socket_fd_, iv_, iv_count_);
        if (temp < 0)
        {
            if (errno == EAGAIN || errno == EWOULDBLOCK) {
                continue;
            }
            else {
                CloseConn(true);
                return;
            }
        }

        bytes_have_send_ += temp;
        bytes_to_send_ -= temp;
        
        if (bytes_to_send_ <= 0)
        {
            Reset();
            return;
        }
    }
#endif // NETWORKEPOLL || NONBLOCKING

#ifdef BLOCKING
    int temp = writev(socket_fd_, iv_, iv_count_);
    bytes_have_send_ += temp;
    bytes_to_send_ -= temp;
    if (temp < 0 || bytes_to_send_ != 0)
    {
        CloseConn(true);
        return;
    }
    else 
    {
        Reset();
        return;
    }
#endif // BLOCKING
}

// Whether multiple requests will occur depends on the client's implementation (e.g., client sends multiple requests
// in a single packet or a open-loop client). In this case, user needs to specify how to determine the number of requests.
int TCPConn::ParseMultiRequest()
{   
    return 1;
}

// Process the request.
void TCPConn::Process(uint64_t* mem_data, uint64_t* curr_mem_addrs, uint64_t* curr_pointer_chasing_mem_addrs, uint64_t &request_id)
{  
    int request_number = ParseMultiRequest();
    
    for (int i = 0; i < request_number; ++i)
    {
        runAssembly(mem_data, request_id, curr_mem_addrs, curr_pointer_chasing_mem_addrs);
        request_id++;
        string res = "reply!Helloworld!Helloworld!Helloworld!\n";
        const char* response = res.c_str();
        strncpy(write_buf_, response, strlen(response));
        write_idx_ = strlen(response);
        iv_[0].iov_base = write_buf_;
        iv_[0].iov_len = write_idx_;
        iv_count_ = 1;
        bytes_to_send_ = write_idx_;
        WriteOnce();
    }
}