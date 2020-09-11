/*************************************************************************
	> File Name: show_stop.c
	> Author: 
	> Mail: 
	> Created Time: 2020年07月04日 星期六 14时22分55秒
 ************************************************************************/

#include "head.h"

extern int sockfd;

void show_stop() {
    struct FootBallMsg msg;
    memset(&msg, 0, sizeof(msg));
    msg.type = FT_CTL;
    msg.ctl.action = ACTION_STOP;
    send(sockfd, (void *)&msg, sizeof(msg), 0);
    return ;
}
