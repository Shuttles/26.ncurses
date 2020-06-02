/*************************************************************************
	> File Name: 1.c
	> Author: 少年宇
	> Mail: 
	> Created Time: 2020年05月31日 星期日 14时11分40秒
 ************************************************************************/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <curses.h>
#include <unistd.h>

int main() {
    initscr();
    for (int i = 0; i < LINES; i++) {
        move(i, i + 1);
        if (i % 2 == 0) 
            /*高亮*/
            standout();
        addstr("Hello HaiZei!");
        if (i % 2 == 0)
            standend();
        sleep(1);
        move(LINES,COLS);
        refresh();
        move(i - 1, i);
        addstr("             ");
        move(LINES - 2, COLS - 2);
        refresh();
    }
    
    getchar();
    endwin();


    return 0;
}
