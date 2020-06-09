/*************************************************************************
	> File Name: datatype.h
	> Author: 少年宇
	> Mail: 
	> Created Time: 2020年06月06日 星期六 20时23分57秒
 ************************************************************************/

#ifndef _DATATYPE_H
#define _DATATYPE_H

#define MAXMSG 1024

struct LogRequest {
    char name[20];
    int team;//0 RED 1 BLUE
    char msg[512];
};

struct LogResponse {
    int type;//表示成功与否 0 success 1 failure
    char msg[512];//为什么没成功
};

struct Point  {
    int x, y;
};

struct User {
    int team;
    int fd;//保存连接
    char name[20];
    int online;
    int flag;//未响应的次数，达到三次就认为不在线
    struct sockaddr_in addr;
    struct Point loc;
};


struct Map {
    int width;
    int height;
    struct Point start;
    int gate_width;
    int gate_height;
};


struct Ctrl {
    int carry;
    int kick;
};

struct TransMsg {
    int dirx, diry;
    struct Ctrl ctrl;
};

#define FT_TEST 0x01
#define FT_WALL 0x02
#define FT_MSG 0x04
#define FT_ACK 0x08

struct FootBallMsg {
    int type;
    int size;
    char msg[MAXMSG];
};

#endif
