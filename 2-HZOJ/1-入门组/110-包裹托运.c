/*************************************************************************
	> File Name: 110-包裹托运.c
	> Author: chenyueze
	> Mail: chen_buzhou@163.com
	> Created Time: 二  9/ 1 16:00:23 2020
 ************************************************************************/

#include<stdio.h>


int main(){
    double x, s;
    scanf("%lf", &x);
    x <= 15 ? s = x * 6 : (s = 15 * 6 + (x - 15) * 9);
    printf("%.2f\n", s);
    return 0;
}
