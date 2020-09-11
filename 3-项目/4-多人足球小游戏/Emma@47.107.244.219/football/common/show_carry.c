/*************************************************************************
	> File Name: show_carry.c
	> Author: 
	> Mail: 
	> Created Time: 2020年07月04日 星期六 15时15分59秒
 ************************************************************************/

#include "head.h"
#include "send_ctl.h"

extern int sockfd;

void show_carry(char *name) {
    struct FootBallMsg msg;
    memset(&msg, 0, sizeof(msg));
    msg.type = FT_CTL;
    msg.ctl.action = ACTION_CARRY;
    strcpy(msg.L_name, name);
    send(sockfd, (void *)&msg, sizeof(msg), 0);
    return ;
}
