/*************************************************************************
	> File Name: client_recver.c
	> Author: 
	> Mail: 
	> Created Time: 2020年06月13日 星期六 23时47分06秒
 ************************************************************************/

#include "head.h"
#include "common.h"
#include "game.h"
#include "show_json.h"

extern int sockfd;

void *client_recver(void *arg) {
    while (1) {
        struct FootBallMsg msg;
        struct User user;
        bzero(&msg, sizeof(msg));
        recv(sockfd, (void *)&msg, sizeof(msg), 0);
        strcpy(user.name, msg.name);
        user.team = msg.team;
        if (msg.type & FT_TEST) {
            DBG(RED"HeartBeat from Server 心\n"NONE);
            msg.type = FT_ACK;
            send(sockfd, (void *)&msg, sizeof(msg), 0);
        } else if (msg.type & FT_MSG) {
            DBG(GREEN"Server Msg :"NONE"%s\n", msg.msg);
            Show_Message(, &user, msg.msg, 0);
        } else if (msg.type & FT_WALL) {
            Show_Message(, NULL, msg.msg, 1);  
        } else if (msg.type & FT_FIN) {
            DBG(GREEN"Server in going stop.\n"NONE);
            endwin();
            exit(0);
        } else if (msg.type & FT_GAME) {
            show_json(msg.msg);
        } else {
            DBG(GREEN"Msg Unsupport\n"NONE);
        }
    }
}
