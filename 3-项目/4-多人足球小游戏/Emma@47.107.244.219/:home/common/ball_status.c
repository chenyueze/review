/*************************************************************************
	> File Name: ball_status.c
	> Author: 
	> Mail: 
	> Created Time: 2020年07月02日 星期四 18时17分29秒
 ************************************************************************/

#include "head.h"
#include <math.h>

extern WINDOW *Message;
extern struct Bpoint ball;
extern struct BallStatus ball_status;

int can_kick(struct Point *loc, int strength) {
    int px = loc->x, py = loc->y;
    if (abs(px - (int)ball.x) <= 2 && abs(py - (int)ball.y) <= 2) {
        if (px == (int)ball.x && py == (int)ball.y) {
            return 0;
        }
        double dx = (ball.x - px) / pow((ball.x - px) * (ball.x - px) + (ball.y - py) * (ball.y - py), 0.5);
        double dy = (ball.y - py) / pow((ball.x - px) * (ball.x - px) + (ball.y - py) * (ball.y - py), 0.5);
        ball_status.a.x = -3 * dx;
        ball_status.a.y = -3 * dy;
        ball_status.v.x = strength * 8 * dx;
        ball_status.v.y = strength * 8 * dy;
        return 1;
    }
    return 0;
}

int can_stop(struct Point *loc) {
    int px = loc->x, py = loc->y;
    if (abs(px - (int)ball.x) <= 2 && abs(py - (int)ball.y) <= 2) {
        ball_status.v.x = ball_status.v.y = 0;
        ball_status.a.x = ball_status.a.y = 0;
        return 1;
    }
    return 0;
}

int can_carry(struct Point *loc) {
    int px = loc->x, py = loc->y;
    if (abs(px - (int)ball.x) <= 2 && abs(py - (int)ball.y) <= 2) {
        if (ball_status.v.x != 0 || ball_status.v.y != 0) {
            return 0;
        } 
        return 1;
    }
    return 0;
}
