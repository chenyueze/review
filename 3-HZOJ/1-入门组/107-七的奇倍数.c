/*************************************************************************
	> File Name: 107-七的奇倍数.c
	> Author: chenyueze
	> Mail: chen_buzhou@163.com
	> Created Time: 二  9/ 1 15:39:05 2020
 ************************************************************************/

#include<stdio.h>


int main(){
    int n;
    scanf("%d", &n);
    !(n % 7) && n % 2 ? printf("YES\n") : printf("NO\n"); 
    return 0;
}
