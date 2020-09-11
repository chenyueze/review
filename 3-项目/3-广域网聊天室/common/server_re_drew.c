/*************************************************************************
	> File Name: server_re_drew.c
	> Author: 
	> Mail: 
	> Created Time: 2020年06月22日 星期一 16时34分22秒
 ************************************************************************/

#include "head.h"
#include "game.h"
#include <math.h>
#define MAX 50

extern struct User *rteam, *bteam;
extern WINDOW *Football, *Football_t;
extern struct Bpoint ball;
extern struct BallStatus ball_status;
extern struct Score score;
extern int flag;

struct Play_json play_json[MAX * 2];
int cnt = 1;

void re_drew_player(int team, char *name, struct Point *loc) {
    char p = 'K';
    if (team)
        wattron(Football, COLOR_PAIR(6));
    else 
        wattron(Football, COLOR_PAIR(2));
    w_gotoxy_putc(Football, loc->x, loc->y, p);
    w_gotoxy_puts(Football, loc->x + 1, loc->y - 1, name);
    play_json[cnt].team = team;
    play_json[cnt].x = loc->x;
    play_json[cnt].y = loc->y;
    strcpy(play_json[cnt].name, name);
    cnt++;
    return ;
}

void re_drew_team(struct User *team) {
    int i;
    for (i = 0 ; i < MAX; i++) {
        if (!team[i].online) continue;
        re_drew_player(team[i].team, team[i].name, &team[i].loc);
    }
    return ;
}

void re_drew_ball() {
    double t = 0.1;
    if (ball_status.v.x != 0 || ball_status.v.y != 0) {
        ball.x += ball_status.v.x * 0.1 + ball_status.a.x * 0.5 * 0.01;
        ball.y += ball_status.v.y * 0.1 + ball_status.a.y * 0.5 * 0.01;
        ball_status.v.x += ball_status.a.x * 0.1;
        ball_status.v.y += ball_status.a.y * 0.1;
    }
    if (fabs(ball_status.v.x) < 0.3) {
        ball_status.a.x = 0;
        ball_status.v.x = 0;
    }
    if (fabs(ball_status.v.y) < 0.3) {
        ball_status.a.y = 0;
        ball_status.v.y = 0;
    }
    if (ball.x <= 0) {
        ball.x = 0;
        ball_status.v.x = ball_status.v.y = 0;
    }
    if (ball.y <= 0) {
        ball.y = 0;
        ball_status.v.x = ball_status.v.y = 0;
    }
    if (ball.x >= court.width - 1) {
        ball.x = court.width - 1; 
        ball_status.v.x = ball_status.v.y = 0;
    }
    if (ball.y >= court.heigth - 1) {
        ball.y = court.heigth - 1;
        ball_status.v.x = ball_status.v.y = 0;
    }
    if (ball.x <= 0 && ball.y >= 10 && ball.y <= 14) {
        score.red += 1;
        flag = 0;
        struct FootBallMsg msg;
        memset(&msg, 0, sizeof(msg));
        msg.type = FT_WALL;
        sprintf(msg.msg, "red : blue = %d : %d", score.red, score.blue);
        int i;
        for (i = 0; i < MAX; i++) {
            if (rteam[i].online) {
                send(rteam[i].fd, (void *)&msg, sizeof(msg), 0);
            }
            if (bteam[i].online) {
                send(bteam[i].fd, (void *)&msg, sizeof(msg), 0);
            }
        }
        ball.x = (int)(court.width / 2);
        ball.y = (int)(court.heigth / 2);
    }
    if (ball.x >= court.width - 1 && ball.y >= 10 && ball.y <= 14) {
        score.blue += 1;
        flag = 0;
        struct FootBallMsg msg;
        memset(&msg, 0, sizeof(msg));
        msg.type = FT_WALL;
        sprintf(msg.msg, "red : blue = %d : %d", score.red, score.blue);
        int i;
        for (i = 0; i < MAX; i++) {
            if (rteam[i].online) {
                send(rteam[i].fd, (void *)&msg, sizeof(msg), 0);
            }
            if (bteam[i].online) {
                send(bteam[i].fd, (void *)&msg, sizeof(msg), 0);
            }
        }
        ball.x = (int)(court.width / 2);
        ball.y = (int)(court.heigth / 2);
    }
    w_gotoxy_putc(Football, (int)ball.x, (int)ball.y, 'o');
    w_gotoxy_putc(Football_t, 1, 11, 'x');
    w_gotoxy_putc(Football_t, 1, 12, 'x');
    w_gotoxy_putc(Football_t, 1, 13, 'x');
    w_gotoxy_putc(Football_t, 1, 14, 'x');
    w_gotoxy_putc(Football_t, 1, 15, 'x');
    w_gotoxy_putc(Football_t, 117, 11, 'x');
    w_gotoxy_putc(Football_t, 117, 12, 'x');
    w_gotoxy_putc(Football_t, 117, 13, 'x');
    w_gotoxy_putc(Football_t, 117, 14, 'x');
    w_gotoxy_putc(Football_t, 117, 15, 'x');
    play_json[0].x = (int)ball.x;
    play_json[0].y = (int)ball.y;
}

char *string = NULL;

void create_monitor() {
    cJSON *team = NULL;
    cJSON *name = NULL;
    cJSON *x = NULL;
    cJSON *y = NULL;
    cJSON *ball_x = NULL;
    cJSON *ball_y = NULL;
    cJSON *resolutions = cJSON_CreateArray();
    cJSON *resolution = NULL;
    cJSON *score_red = NULL;
    cJSON *score_blue = NULL;

    cJSON *monitor = cJSON_CreateObject();
    
    score_red = cJSON_CreateNumber(score.red);
    score_blue = cJSON_CreateNumber(score.blue);
    cJSON_AddItemToObject(monitor, "score_red", score_red);
    cJSON_AddItemToObject(monitor, "score_blue", score_blue);
    ball_x = cJSON_CreateNumber(play_json[0].x);
    ball_y = cJSON_CreateNumber(play_json[0].y);
    cJSON_AddItemToObject(monitor, "ball_x", ball_x);
    cJSON_AddItemToObject(monitor, "ball_y", ball_y);

    cJSON_AddItemToObject(monitor, "resolutions", resolutions);
    
    int i;
    for (i = 1; i < cnt; i++) {
        resolution = cJSON_CreateObject();
        team = cJSON_CreateNumber(play_json[i].team);
        x = cJSON_CreateNumber(play_json[i].x);
        y = cJSON_CreateNumber(play_json[i].y);
        name = cJSON_CreateString(play_json[i].name);
        cJSON_AddItemToObject(resolution, "team", team);
        cJSON_AddItemToObject(resolution, "name", name);
        cJSON_AddItemToObject(resolution, "x", x);
        cJSON_AddItemToObject(resolution, "y", y);
        cJSON_AddItemToArray(resolutions, resolution);
    }
    string = cJSON_Print(monitor);
    
    cJSON_Delete(monitor);
    return ;
}


void send_json() {
    struct FootBallMsg msg_json;
    memset(&msg_json, 0, sizeof(msg_json));
    msg_json.type = FT_GAME;
    strcpy(msg_json.msg, string);
    int i;
    for (i = 0; i < MAX; i++) {
        if (!rteam[i].online) continue;
        send(rteam[i].fd, (void *)&msg_json, sizeof(msg_json), 0);
    }
    for (i = 0; i < MAX; i++) {
        if (!bteam[i].online) continue;
        send(bteam[i].fd, (void *)&msg_json, sizeof(msg_json), 0);
    }
    return ;
}

void re_drew() {
    cnt = 1;
    wclear(Football_t);
    wclear(Football);
    box(Football_t, 0, 0);
    box(Football, 0, 0);
    re_drew_team(rteam);
    re_drew_team(bteam);
    re_drew_ball();
    wrefresh(Football_t);
    wrefresh(Football);
    create_monitor();
    send_json();
    return ;
}
