/*************************************************************************
	> File Name: server.c
	> Author: 少年宇
	> Mail: 
	> Created Time: 2020年06月02日 星期二 18时13分44秒
 ************************************************************************/

#include "../common/color.h"
#include "../common/head.h"
#include "../common/common.h"
#include "../common/udp_server.h"
#include "../game.h"

char *conf = "./server.conf";

//struct Map court;

struct User *rteam;
struct User *bteam;
int data_port;

int main(int argc, char **argv) {
    int opt, port = 0, listener, epoll_fd;
    pthread_t draw_t;
    while ((opt = getopt(argc, argv, "p:")) != -1) {
        switch (opt) {
            case 'p':
                port = atoi(optarg);
                break;
            default:
                fprintf(stderr, "Usage : %s [-p port]\n", argv[0]);
                exit(1);
        }
    }

    argc -= (optind - 1);
    argv += (optind - 1);

    if (argc > 1) {
        fprintf(stderr, "Usage : %s [-p port]\n", argv[0]);
        exit(1);
    }

    if (!port) port = atoi(get_value(conf, "PORT"));
    data_port = atoi(get_value(conf, "DATAPORT"));
    court.width = atoi(get_value(conf, "COLS"));
    court.height = atoi(get_value(conf, "LINES"));
    court.start.x = 1;
    court.start.y = 1;

    rteam = (struct User *)calloc(MAX, sizeof(struct User));
    bteam = (struct User *)calloc(MAX, sizeof(struct User));


    /*创建udp套接字*/
    if ((listener = socket_create_udp(port)) < 0) {
        perror("socket_create_udp");
        exit(1);
    }




    DBG(GREEN"INFO"NONE" : Server start on Port %d\n", port);

    

    pthread_create(&draw_t, NULL, draw, NULL);
    

    epoll_fd = epoll_create(MAX * 2);

    if (epoll_fd < 0) {
        perror("epoll_create");
        exit(1);
    }

    struct epoll_event ev, events[MAX * 2];

    ev.events = EPOLLIN;
    ev.data.fd = listener;

    epoll_ctl(epoll_fd, EPOLL_CTL_ADD, listener, &ev);

    struct LogData lg;
    struct sockaddr_in client;
    socklen_t len = sizeof(client);

    while (1) {
        w_gotoxy_puts(Message, 1, 1, "Wait for login");
        wrefresh(Message);
        int nfds = epoll_wait(epoll_fd, events, MAX * 2, -1);
        
        for (int i = 0; i < nfds; i++) {
            char info[1024] = {0};
            recvfrom(events[i].data.fd, (void *)&lg, sizeof(lg), 0, (struct sockaddr *)&client, &len);
            sprintf(info, "Login: %s : %d", inet_ntoa(client.sin_addr), client.sin_port);
            w_gotoxy_puts(Message, 1, 2, info);
        }

    }
    
    

    return 0;
}