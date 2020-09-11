/*************************************************************************
	> File Name: server.c
	> Author: chenyueze
	> Mail: chen_buzhou@163.com
	> Created Time: 五  9/11 16:44:45 2020
 ************************************************************************/

#include<stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[]){
    if(argc != 2){
        fprintf(stderr, "Usage: %s port. \n", argv[0]);
        exit(1);
    }
    int port, server_listen;
    port = atoi(argv[1]);
    if((server_listen = socket(AF_INET, SOCK_STREAM, 0)) < 0){
        perror("socket");
        exit(1);
    }

    struct sockaddr_in server;
    server.sin_family = AF_INET;
    server.sin_port = htons(port);
    server.sin_addr.s_addr = INADDR_ANY;


    if(bind(server_listen, (struct sockaddr *)&server, sizeof(server)) < 0){
        perror("bind");
        exit(1);
    }

    if(listen(server_listen, 20) < 0){
        perror("listen");
        exit(1);
    }

    while(1){
    }

    return 0;
}
