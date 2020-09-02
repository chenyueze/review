/*************************************************************************
	> File Name: 114-他的名字.c
	> Author: chenyueze
	> Mail: chen_buzhou@163.com
	> Created Time: 二  9/ 1 16:28:16 2020
 ************************************************************************/

#include<stdio.h>


int main(){
    char x;
    scanf("%c", &x);
    switch(x){
        case 'h':printf("He\n"); break;
        case 'l':printf("Li\n"); break;
        case 'c':printf("Cao\n"); break;
        case 'd':printf("Duan\n"); break;
        case 'w':printf("Wang\n"); break;
        default : printf("Not Here\n"); break;
    }
    return 0;
}
