/*************************************************************************
	> File Name: tcp_client_timeout.c
	> Author: 
	> Mail: 
	> Created Time: 2020年04月10日 星期五 19时46分07秒
 ************************************************************************/

#include "head.h"

int socket_connect_timeout(char *host, int port) {
    int sockfd;
    struct sockaddr_in server;
    server.sin_family = AF_INET;
    server.sin_port = htons(port);
    server.sin_addr.s_addr = inet_addr(host);

    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("socket");
        return -1;
    }

    make_nonblock(sockfd);

    if (connect(sockfd, (struct sockaddr *)&server, sizeof(server)) == 0) {
        make_block(sockfd);
        return sockfd;
    } else {
        int retval;
        fd_set rfds;
        FD_ZERO(&rfds);
        FD_SET(sockfd, &rfds);

        struct timeval tv;
        tv.tv_sec = 5;
        tv.tv_usec = 0;

        retval = select(1, &rfds, NULL, NULL, &tv);

        if (retval < 0) {
            perror("select");
            return -1;
        } else if (retval == 0) {
            printf("connect overtime!\n");
        } else {
            make_block(sockfd);
            return sockfd;
        }
    }
    return -1;
}
