/*************************************************************************
	> File Name: 112-按要求输出.c
	> Author: chenyueze
	> Mail: chen_buzhou@163.com
	> Created Time: 二  9/ 1 16:13:45 2020
 ************************************************************************/

#include<stdio.h>

int main(){
    char x;
    scanf("%c", &x);
    switch (x){
        case 'a': printf("It is good\n"); break;
        case 'b': printf("OMG\n"); break;
        case 'c': printf("Yes!\n"); break;
    }
    return 0;
}
