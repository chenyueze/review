/*************************************************************************
	> File Name: show_strength.c
	> Author: 
	> Mail: 
	> Created Time: 2020年06月30日 星期二 19时54分44秒
 ************************************************************************/

#include "head.h"
#include "common.h"

extern WINDOW *Write;
extern int sockfd;

void show_strength() {
    int mousex = 2, offset = 1;
    int maxx, maxy, strength;
    getmaxyx(Write, maxy, maxx);
    int i;
    for (i = 2; i < maxx - 2; i++) {
        if (i < maxx / 5 || i > maxx - maxx / 5) {
            wattron(Write, COLOR_PAIR(9));
        } else if (i < (maxx / 5) * 2 || i > (maxx / 5) * 3) {
            wattron(Write, COLOR_PAIR(12));
        } else {
            wattron(Write, COLOR_PAIR(8));
        }
        mvwprintw(Write, 2, i, " ");
    }
    wattron(Write, COLOR_PAIR(3));
    make_nonblock(0);
    while (1) {
        char c = getchar();
        if (c != -1) {
            if (c == ' ' || c == 'k') {
                make_block(0);
                break;
            }
        }
        usleep(30000);
        if (mousex >= maxx - 2) {
            offset = -1;
        } else if (mousex <= 2) {
            offset = 1;
        }
        mvwprintw(Write, 1, mousex, " ");
        mvwprintw(Write, 3, mousex, " ");
        mousex += offset;
        mvwprintw(Write, 1, mousex, "|");
        mvwprintw(Write, 3, mousex, "|");
        mvwprintw(Write, 4, maxx, " ");
        wrefresh(Write);
    }
    int arr[5] = {1, 2, 3, 2, 1};
    struct FootBallMsg msg;
    memset(&msg, 0, sizeof(msg));
    msg.type = FT_CTL;
    msg.ctl.action = ACTION_KICK;
    msg.ctl.strength = arr[mousex / (maxx / 5)];
    send(sockfd, (void *)&msg, sizeof(msg), 0);
    werase(Write);
    box(Write, 0, 0);
    wrefresh(Write);
    return ;
}
