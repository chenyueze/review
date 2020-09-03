/*************************************************************************
	> File Name: 11-gcd.c
	> Author: chenyueze
	> Mail: chen_buzhou@163.com
	> Created Time: 三  9/ 2 21:26:48 2020
 ************************************************************************/

#include<stdio.h>

#define P(func) {\
    printf("%s = %d\n", #func, func);\
}

int gcd(int a, int b){
    return (b ? gcd(b, a % b) : a);
}

int main(){
    int a, b;
    scanf("%d%d", &a, &b);
    P(gcd(a, b));
    return 0;
}
