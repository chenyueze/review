/*************************************************************************
	> File Name: udp_client.c
	> Author: 
	> Mail: 
	> Created Time: 2020年06月04日 星期四 18时55分00秒
 ************************************************************************/

#include "head.h"

int socket_udp() {
    int sockfd;
    if ((sockfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0) {
        perror("socket");
        exit(1);
    }
    printf("Socket create.\n");
    return sockfd;
}
