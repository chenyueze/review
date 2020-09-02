/*************************************************************************
	> File Name: 106-求绝对值.c
	> Author: chenyueze
	> Mail: chen_buzhou@163.com
	> Created Time: 二  9/ 1 15:32:40 2020
 ************************************************************************/

#include<stdio.h>


int main(){
    double n;
    scanf("%lf", &n);
    n >= 0 ? printf("%g\n", n) : printf("%g\n", -n);
    return 0;
}
