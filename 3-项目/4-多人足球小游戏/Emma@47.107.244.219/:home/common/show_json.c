/*************************************************************************
	> File Name: show_json.c
	> Author: 
	> Mail: 
	> Created Time: 2020年07月05日 星期日 19时39分37秒
 ************************************************************************/

#include "head.h"
#include "game.h"
#define MAX 50

struct Play_json play_json[MAX * 2];
extern WINDOW *Football, *Football_t, *Score;
struct Score score;
char red[5];
char blue[5];

void show_json(char *string) {
    score.red = score.blue = 0; 
    int cnt = 1;
    memset(&red, 0, sizeof(red));
    memset(&blue, 0, sizeof(blue));
    wclear(Football_t);
    wclear(Football);
    box(Football_t, 0, 0);
    box(Football, 0, 0);
    cJSON *team = NULL;
    cJSON *name = NULL;
    cJSON *x = NULL;
    cJSON *y = NULL;
    cJSON *ball_x = NULL;
    cJSON *ball_y = NULL;
    cJSON *resolution = NULL;
    cJSON *resolutions = NULL;
    cJSON *score_red = NULL;
    cJSON *score_blue = NULL;
    cJSON *monitor_json = cJSON_Parse(string);
    
    score_red = cJSON_GetObjectItemCaseSensitive(monitor_json, "score_red");
    score_blue = cJSON_GetObjectItemCaseSensitive(monitor_json, "score_blue");
    ball_x = cJSON_GetObjectItemCaseSensitive(monitor_json, "ball_x");
    ball_y = cJSON_GetObjectItemCaseSensitive(monitor_json, "ball_y");
    cJSON_IsNumber(score_red);
    cJSON_IsNumber(score_blue);
    cJSON_IsNumber(ball_x);
    cJSON_IsNumber(ball_y);
    score.red = score_red->valueint;
    score.blue = score_blue->valueint;
    play_json[0].x = ball_x->valueint;
    play_json[0].y = ball_y->valueint;
    DBG(L_RED"red : blue = %d  : %d"NONE, score.red, score.blue);
    sprintf(red, "%d", score.red);
    sprintf(blue, "%d", score.blue);

    resolutions = cJSON_GetObjectItem(monitor_json, "resolutions");
    DBG(L_RED"1"NONE);
    if (resolutions != NULL) {
        resolution = resolutions->child;
        DBG(L_RED"2"NONE);
        while (resolution != NULL) {
        team = cJSON_GetObjectItemCaseSensitive(resolution, "team");
        x = cJSON_GetObjectItemCaseSensitive(resolution, "x");
        y = cJSON_GetObjectItemCaseSensitive(resolution, "y");
        name = cJSON_GetObjectItemCaseSensitive(resolution, "name");
        cJSON_IsNumber(team);
        cJSON_IsNumber(x);
        cJSON_IsNumber(y);
        cJSON_IsString(name);
        play_json[cnt].team = team->valueint;
        play_json[cnt].x = x->valueint;
        play_json[cnt].y = y->valueint;
        sprintf(play_json[cnt].name, "%s", name->valuestring);
        cnt++;
        resolution = resolution->next;
    DBG(L_RED"play_json.x.y = %d, %d\n"NONE, play_json[--cnt].x, play_json[--cnt].y);
        }
    }
    cJSON_Delete(monitor_json);
    int i;
    for (i = 1; i < cnt; i++) {
        char p = 'K';
        if (play_json[i].team) {
            wattron(Football, COLOR_PAIR(6));
        } else {
            wattron(Football, COLOR_PAIR(2));
        }
        w_gotoxy_putc(Football, play_json[i].x, play_json[i].y, p);
        w_gotoxy_puts(Football, play_json[i].x + 1, play_json[i].y - 1, play_json[i].name);
    }
    DBG(L_RED"score.red : score.blue = %d : %d"NONE, score.red, score.blue); 
    w_gotoxy_putc(Football, play_json[0].x, play_json[0].y, 'o');
    w_gotoxy_putc(Score, 8, 2, ':');
    w_gotoxy_putc(Score, 8, 3, ':');
    wattron(Football_t, COLOR_PAIR(6));
    wattron(Score, COLOR_PAIR(6));
    w_gotoxy_puts(Score, 10, 2, "BLUE");
    w_gotoxy_puts(Score, 11, 3, blue);
    w_gotoxy_putc(Football_t, 1, 11, 'x');
    w_gotoxy_putc(Football_t, 1, 12, 'x');
    w_gotoxy_putc(Football_t, 1, 13, 'x');
    w_gotoxy_putc(Football_t, 1, 14, 'x');
    w_gotoxy_putc(Football_t, 1, 15, 'x');
    wattron(Football_t, COLOR_PAIR(2));
    wattron(Score, COLOR_PAIR(2));
    w_gotoxy_puts(Score, 4, 2, "RED");
    w_gotoxy_puts(Score, 5, 3, red);
    w_gotoxy_putc(Football_t, 117, 11, 'x');
    w_gotoxy_putc(Football_t, 117, 12, 'x');
    w_gotoxy_putc(Football_t, 117, 13, 'x');
    w_gotoxy_putc(Football_t, 117, 14, 'x');
    w_gotoxy_putc(Football_t, 117, 15, 'x');
    wattroff(Score, COLOR_PAIR(2));
    wrefresh(Football_t);
    wrefresh(Football);
    return ;
}

