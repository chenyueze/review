/*************************************************************************
	> File Name: thread_pool.c
	> Author: 
	> Mail: 
	> Created Time: 2020年06月09日 星期二 18时14分03秒
 ************************************************************************/

#include "head.h"
#include "thread_pool.h" 
#include "udp_epoll.h"
#include "game.h"
#include "show_data_stream.h"
#include "ball_status.h"

extern int repollfd, bepollfd;

extern struct Bpoint ball;
extern struct BallStatus ball_status;
int flag;
char L_name[20];

void do_echo(struct User *user) {
    struct FootBallMsg msg;
    char tmp[512] = {0};
    int size = recv(user->fd, (void *)&msg, sizeof(msg), 0);
    user->flag = 10;
    if (msg.type & FT_ACK) {
        if (user->team) 
            DBG(L_BLUE" %s "NONE"心\n", user->name);
        else 
            DBG(L_RED" %s "NONE"心\n", user->name);
        user->flag = 10;
    } else if (msg.type & (FT_WALL | FT_MSG)) {
        if (user->team) 
            DBG(L_BLUE" %s : %s"NONE, user->name, msg.msg);
        else 
            DBG(L_RED" %s : %s"NONE, user->name, msg.msg);
        strcpy(msg.name, user->name);
        msg.team = user->team;
        Show_Message(, user, msg.msg, );
        send(user->fd, (void *)&msg, sizeof(msg), 0);
    } else if (msg.type & FT_FIN) {
        DBG(RED"%s logout.\n"NONE, user->name);
        sprintf(tmp, "%s Logout.", user->name);
        Show_Message(, NULL, tmp, 1);
        user->online = 0;
        int epollfd_tem = (user->team ? bepollfd : repollfd);
        del_event(epollfd_tem, user->fd);
        show_data_stream('e');
    } else if (msg.type & FT_CTL) {
        Show_Message(, user, "Ctrl Message", 0);
        if (msg.ctl.dirx || msg.ctl.diry) {
            user->loc.x += msg.ctl.dirx;
            user->loc.y += msg.ctl.diry;
            if (user->loc.x <= -1) user->loc.x = -1;
            if (user->loc.x >= court.width) user->loc.x = court.width;
            if (user->loc.y <= -1) user->loc.y = -1;
            if (user->loc.y >= court.heigth) user->loc.y = court.heigth;
            if (flag && (strcmp(L_name, user->name) == 0)) {
                ball.x += msg.ctl.dirx;
                ball.y += msg.ctl.diry;
            }
        }
        if (msg.ctl.action & ACTION_KICK) {
            show_data_stream('k');
            if (can_kick(&user->loc, msg.ctl.strength)) {
                ball_status.who = user->team;
                strcpy(ball_status.name, user->name);
                flag = 0;
            }
        }
        if (msg.ctl.action & ACTION_STOP) {
            show_data_stream('s');
            if (can_stop(&user->loc)) {
                ball_status.who = user->team;
                strcpy(ball_status.name, user->name);
                flag = 0;
            }
        }
        if (msg.ctl.action & ACTION_CARRY) {
            show_data_stream('c');
            if (can_carry(&user->loc)) {
                memset(&L_name, 0, sizeof(L_name));
                strcpy(L_name, msg.L_name);
                flag = 1;
            }
        }
        show_data_stream('n');
    }
}

void task_queue_init(struct task_queue *taskQueue, int sum, int epollfd) {
    taskQueue->sum = sum;
    taskQueue->epollfd = epollfd;
    taskQueue->team = calloc(sum, sizeof(void *));
    taskQueue->head = taskQueue->tail = 0;
    pthread_mutex_init(&taskQueue->mutex, NULL);
    pthread_cond_init(&taskQueue->cond, NULL);
}

void task_queue_push(struct task_queue *taskQueue, struct User *user) {
    pthread_mutex_lock(&taskQueue->mutex);
    taskQueue->team[taskQueue->tail] = user;
    DBG(L_GREEN"Thread Pool :"NONE" Task Push %s\n", user->name);
    if (++taskQueue->tail == taskQueue->sum) {
        DBG(L_GREEN"Thread Pool : "NONE" Task Queue End.\n");
        taskQueue->tail = 0;
    }
    pthread_cond_signal(&taskQueue->cond);
    pthread_mutex_unlock(&taskQueue->mutex);
}

struct User *task_queue_pop(struct task_queue *taskQueue) {
    pthread_mutex_lock(&taskQueue->mutex);
    while (taskQueue->tail == taskQueue->head) {
        DBG(L_GREEN"Thread Pool : "NONE" Task Queue Empty.\n"); 
        pthread_cond_wait(&taskQueue->cond, &taskQueue->mutex);
    }
    struct User *user = taskQueue->team[taskQueue->head];
    DBG(L_GREEN"Thread Pool : "NONE" Task pop\n");
    if (++taskQueue->head == taskQueue->sum) {
        DBG(L_GREEN"Thread Pool : "NONE" Task Queue End.\n");
        taskQueue->head = 0;
    }
    pthread_mutex_unlock(&taskQueue->mutex);
    return user;
}

void *thread_run(void *arg) {
    pthread_t tid = pthread_self();
    pthread_detach(tid);
    struct task_queue *taskQueue = (struct task_queue *)arg;
    while (1) {
        struct User *user = task_queue_pop(taskQueue);
        do_echo(user);
    }
}


