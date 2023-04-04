#include <arpa/inet.h>  //网络通信相关
#include <errno.h>      //错误号相关
#include <fcntl.h>      //文件描述符相关
#include <libgen.h>     //basename()函数是POSIX标准的一部分
#include <stdlib.h>
#include <sys/epoll.h>
#include <unistd.h>
#include <iostream>
#include <string>
#include "locker.h"      //同步类
#include "threadpool.h"  //线程池，用于一开始创建线程池，运行，执行任务，加入队列
int main(int argc, char* argv[]) {
    if (argc <= 1) {
        std::cout << "运行格式: " << (basename(argv[0])) << "port_number"
                  << std::endl;
        exit(-1);
    }
    //获取端口号
    int port = atoi(argv[1]);
    
    return 0;
}