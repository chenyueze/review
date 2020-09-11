/*************************************************************************
	> File Name: test.c
	> Author: 
	> Mail: 
	> Created Time: 2020年06月14日 星期日 16时31分14秒
 ************************************************************************/

#include "../common/head.h"

cJSON *ft_msg() {
        cJSON *root = cJSON_CreateObject();
        cJSON_AddItemToObject(root, "FT_TEST", cJSON_CreateString("0x01"));
        cJSON_AddItemToObject(root, "FT_WALL", cJSON_CreateString("0x02"));
        cJSON_AddItemToObject(root, "FT_MSG", cJSON_CreateString("0x04"));
        cJSON_AddItemToObject(root, "FT_ACK", cJSON_CreateString("0x08"));
        cJSON_AddItemToObject(root, "FT_FIN", cJSON_CreateString("0x10"));
        cJSON_AddItemToObject(root, "FT_CTL", cJSON_CreateString("0x20"));
        cJSON_AddItemToObject(root, "FT_GAME", cJSON_CreateString("0x40"));
        cJSON_AddItemToObject(root, "FT_SCORE", cJSON_CreateString("0x80"));
        cJSON_AddItemToObject(root, "FT_GAMEOVER",cJSON_CreateString("0x100"));
        return root;
}

int main() {
        printf("%s\n", cJSON_Print(ft_msg()));
        return 0;
}
