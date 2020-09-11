/*************************************************************************
	> File Name: server_exit.c
	> Author: 
	> Mail: 
	> Created Time: 2020年06月14日 星期日 00时35分57秒
 ************************************************************************/

#include "head.h"
#define MAX 50

extern struct User *rteam, *bteam;

void server_exit(int signum) {
    struct FootBallMsg msg;
    msg.type = FT_FIN;
    int i;
    for (i = 0; i < MAX; i++) {
        if (rteam[i].online) send(rteam[i].fd, (void *)&msg, sizeof(msg), 0);
        if (bteam[i].online) send(bteam[i].fd, (void *)&msg, sizeof(msg), 0);
    }
    endwin();
    DBG(RED"Server stopped!\n"NONE);
    exit(0);
}

