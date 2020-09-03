/*************************************************************************
	> File Name: 12-ex_gcd.c
	> Author: chenyueze
	> Mail: chen_buzhou@163.com
	> Created Time: 三  9/ 2 21:40:21 2020
 ************************************************************************/

#include<stdio.h>

int ex_gcd(int a, int b, int *x, int *y){
    if(!b) {
        *x = 1;
        *y = 0;
        return a;
    }
    int xx, yy, ret = ex_gcd(b, a % b, y, x);
    /**x = yy;
    *y = xx - a / b * yy;*/
    *y -= a / b * (*x);
    return ret;
}

int main() {
    int a, b, x, y;
    scanf("%d%d", &a, &b);
    printf("gcd(%d, %d) = %d \n", a, b, ex_gcd(a, b, &x, &y));
    printf("%d * %d + %d * %d = %d\n", a, x, b, y, a * x + b * y);
    return 0;
}
