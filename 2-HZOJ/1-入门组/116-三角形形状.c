/*************************************************************************
	> File Name: 116-三角形形状.c
	> Author: chenyueze
	> Mail: chen_buzhou@163.com
	> Created Time: 二  9/ 1 16:44:12 2020
 ************************************************************************/

#include<stdio.h>

#define swap(a, b) {\
    a ^= b;\
    b ^= a;\
    a ^= b;\
}

int main(){
    int a, b, c;
    scanf("%d%d%d", &a, &b, &c);
    if(a > b) swap(a, b);
    if(a > c) swap(a, c);
    if(b > c) swap(b, c);
    if(a + b < c) {
        printf("illegal triangle\n");
        return 0;
    }
    int d = a * a + b * b - c * c;
    if(d == 0){
        printf("right triangle\n");
    }else if(d > 0){
        printf("acute triangle\n");
    }else{
        printf("obtuse triangle\n");
    }
    return 0;
}
