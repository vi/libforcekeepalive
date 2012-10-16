#define _GNU_SOURCE 1
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <dlfcn.h>
#include <sys/time.h>
#include <sys/select.h>
#include <time.h>
#include <sys/stat.h>
#include <sys/socket.h>
#include <fcntl.h>
#include <poll.h>
#include <errno.h>

                   
static int (*orig_connect)(int sockfd, const struct sockaddr *addr,
                   socklen_t addrlen) = NULL;
static int (*orig_accept)(int sockfd, struct sockaddr *addr, socklen_t *addrlen) = NULL;

            
                        
int connect (int sockfd, const struct sockaddr *addr,
                   socklen_t addrlen) {
    if(!orig_connect) { 
        orig_connect = dlsym(RTLD_NEXT, "connect");
    }
    
    int ret = orig_connect(sockfd, addr, addrlen);
    
    if (ret!=-1) {
        int val = 1;
        setsockopt(sockfd, SOL_SOCKET, SO_KEEPALIVE, &val, sizeof val);
    }
    
    return ret;
}

int accept (int sockfd, struct sockaddr *addr, socklen_t *addrlen) {
    if(!orig_accept) {
        orig_accept = dlsym(RTLD_NEXT, "accept");
    }
    
    int ret = orig_accept(sockfd, addr, addrlen);
    
    if (ret!=-1) {
        int val = 1;
        setsockopt(ret, SOL_SOCKET, SO_KEEPALIVE, &val, sizeof val);
    }
    
    return ret;
}