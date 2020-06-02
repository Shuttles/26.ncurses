/*************************************************************************
	> File Name: sleep.c
	> Author: 少年宇
	> Mail: 
	> Created Time: 2020年05月31日 星期日 15时04分29秒
 ************************************************************************/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

void print() {
    printf("It's time to getup!\n");
}

int main() {
    signal(14, print);
    alarm(10);
    pause();

    return 0;
}
