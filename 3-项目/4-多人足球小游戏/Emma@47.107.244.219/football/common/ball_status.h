/*************************************************************************
	> File Name: ball_status.h
	> Author: 
	> Mail: 
	> Created Time: 2020年07月02日 星期四 18时17分24秒
 ************************************************************************/

#ifndef _BALL_STATUS_H
#define _BALL_STATUS_H
int can_kick(struct Point *loc, int strength);
int can_stop(struct Point *loc);
int can_carry(struct Point *loc);
#endif
