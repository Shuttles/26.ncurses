/*************************************************************************
	> File Name: itimer.c
	> Author: 少年宇
	> Mail: 
	> Created Time: 2020年05月31日 星期日 15时53分59秒
 ************************************************************************/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/time.h>
#include <signal.h>
#include <unistd.h>


void print() {
    printf("Recv a signal!\n");
    return ;
}


int main() {
    struct itimerval itm;
    signal(14, print);
    itm.it_interval.tv_sec = 1;
    itm.it_interval.tv_usec = 0;
    itm.it_value.tv_sec = 3;
    itm.it_value.tv_usec = 3;
    
    setitimer(ITIMER_REAL, &itm, NULL);
    while (1) {
        sleep(10);//为了避免成为CPU约束型
        printf("After sleep!\n"); 
    }

    return 0;
}
