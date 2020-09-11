/*************************************************************************
	> File Name: daratype.h
	> Author: 
	> Mail: 
	> Created Time: 2020年06月07日 星期日 13时51分59秒
 ************************************************************************/

#ifndef _DARATYPE_H
#define _DARATYPE_H
#define MAXMSG 1024
struct LogRequest{
        char name[20];
        int team;// 0 RED 1 BLUE
        char msg[512];
};

struct LogResponse{
        int type;
        char msg[512];
};

struct Point{
        int x;
        int y;
};

struct Bpoint {
  double x;
    double y;
};

struct User{
        int team;
        int fd;
        char name[20];
        int online;
        int flag; // 未响应次数
        struct Point loc;
};

struct Map{
        int width;
        int heigth;
        struct Point start;
        int gate_width;
        int gate_heigth;
};

#define ACTION_KICK 0x01
#define ACTION_CARRY 0x02
#define ACTION_STOP 0x04

struct Ctrl {
    int action;
        int dirx;
        int diry;
    int strength;
};

#define FT_TEST 0x01   //服务器心跳信息
#define FT_WALL 0x02  //服务端以字符串方式广播游戏情况
#define FT_MSG 0x04   //客户端发送的信息，服务端转发的信息
#define FT_ACK 0x08   //客户端对心跳的ACK确认
#define FT_FIN 0x10   //客户端，服务端下线前，对彼此的告知
#define FT_CTL 0x20   //客户端发送的控制信息
#define FT_GAME 0x40   //服务端向客户端广播的游戏实时图画  json发送
#define FT_SCORE 0x80   //服务端对客户端广播的游戏比分变化，json发送(包括进球人)
#define FT_GAMEOVER 0x100   //游戏结束

struct FootBallMsg{
    int type;
    int size;
    int team;
    char name[20];
    struct Ctrl ctl;
    char msg[MAXMSG];
    char L_name[20];
};

struct Aspeed{
        double x;
        double y;
};

struct Speed{
        double x;
        double y;
};


struct BallStatus {
        struct Speed v;
        struct Aspeed a;
        int t;
        int who;
        char name[20];
        //pthread_mutex_t mutex;
};

struct Score{
    int red;
    int blue;
};

struct Play_json{
    int team;
    char name[20];
    int x; 
    int y;
};

#endif
