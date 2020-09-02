/*************************************************************************
	> File Name: 115-彩票.c
	> Author: chenyueze
	> Mail: chen_buzhou@163.com
	> Created Time: 二  9/ 1 16:31:52 2020
 ************************************************************************/

#include<stdio.h>

int main(){
    int num[15] = {0};
    int x, y, s;
    scanf("%d%d", &x, &y);
    if(x == y) {
        s = 100;
    }else{
        num[x % 10] = 1;
        x /= 10;
        num[x] = 1;
        if(num[y % 10] == 1) num[10] += 1;
        y /= 10;
        if(num[y] == 1) num[10] += 1;
        switch(num[10]){
            case 0: s = 0; break;
            case 1: s = 2; break;
            case 2: s = 20; break;
        }
    }
    printf("%d\n", s);
    return 0;
}
