/*************************************************************************
	> File Name: udp_client.c
	> Author: 少年宇
	> Mail: 
	> Created Time: 2020年06月04日 星期四 18时48分38秒
 ************************************************************************/

#include "head.h"

int socket_udp() {
    int sockfd;
    if ((sockfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0) {
        perror("socket");
        return -1;
    }
    printf("Socket create.\n");
    return sockfd;
}
