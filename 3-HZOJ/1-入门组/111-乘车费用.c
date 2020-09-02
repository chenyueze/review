/*************************************************************************
	> File Name: 111-乘车费用.c
	> Author: chenyueze
	> Mail: chen_buzhou@163.com
	> Created Time: 二  9/ 1 16:07:15 2020
 ************************************************************************/

#include<stdio.h>


int main(){
    double n;
    scanf("%lf", &n);
    n <= 3 ? printf("14") : printf("%.1f", 14 + (n - 3) * 2.3);
    return 0;
}
