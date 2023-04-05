#ifndef HTTPCONNECTION_H
#define HTTPCONNECTION_H
#include <arpa/inet.h>
#include <errno.h>
#include <fcntl.h>
#include <netinet/in.h>
#include <signal.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/epoll.h>
#include <sys/mman.h>
#include <sys/socket.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>

#include <iostream>

#include "locker.h"
class http_conn {
   public:
    static int m_epollfd;  // 所有的socket上的事件都被注册到同一个epoll对象中
    static int m_user_count;  // 统计用户的数量
    http_conn() {}
    ~http_conn() {}
    void process();                                  // 处理客户端请求
    void init(int sockfd, const sockaddr_in& addr);  // 初始化新接收的连接
    void close_conn();                               // 关闭连接
    bool read();                                     // 非阻塞的读
    bool write();                                    // 非阻塞的写

   private:
    int m_sockfd;           // 该HTTP连接的socket
    sockaddr_in m_address;  // 通信的socket地址
};
#endif