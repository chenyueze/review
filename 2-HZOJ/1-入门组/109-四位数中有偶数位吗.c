/*************************************************************************
	> File Name: 109-四位数中有偶数位吗.c
	> Author: chenyueze
	> Mail: chen_buzhou@163.com
	> Created Time: 二  9/ 1 15:51:18 2020
 ************************************************************************/

#include<stdio.h>


int main (){
    int n, flag = 1;
    scanf("%d", &n);
    while(n && flag){
        flag = (n % 10) & 1;
        n /= 10;
    }
    flag ? printf("NO\n") : printf("YES\n");
    return 0;
}
