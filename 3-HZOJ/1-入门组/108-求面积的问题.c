/*************************************************************************
	> File Name: 108-求面积的问题.c
	> Author: chenyueze
	> Mail: chen_buzhou@163.com
	> Created Time: 二  9/ 1 15:42:34 2020
 ************************************************************************/

#include<stdio.h>

int main(){
    double m, n, s;
    char c;
    scanf("%c", &c);
    scanf("%lf %lf", &m,&n);
    c == 'r' ? s = m * n : (s = m * n / 2);
    printf("%.2f\n", s);
    return 0;
}
