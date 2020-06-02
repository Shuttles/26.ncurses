#include "head.h"
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdlib.h>


int main(int argc, char **argv) {
    if (argc != 3) {
        fprintf(stderr, "Usage: ./a.out ip port\n");
        return -1;
    }
    int sockfd;
    struct sockaddr_in server;
    int port = atoi(argv[2]);
    server.sin_family = AF_INET;
    server.sin_port = htons(port);
    server.sin_addr.s_addr = inet_addr(argv[1]);

    if ((sockfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0) {
        perror("socket");
        return -1;
    }
    printf("Socket create\n");
    char msg[1024];
    while (1) {
        fgets(msg, sizeof(msg), stdin);
        sendto(sockfd, msg, sizeof(msg), 0, (struct sockaddr *)&server, sizeof(server));
    }
    close(sockfd);
    printf("send end\n");
    return 0;
}

