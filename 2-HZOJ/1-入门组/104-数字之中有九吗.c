/*************************************************************************
	> File Name: 104-数字之中有九吗.c
	> Author: chenyueze
	> Mail: chen_buzhou@163.com
	> Created Time: 二  9/ 1 15:24:50 2020
 ************************************************************************/

#include<stdio.h>

int main(){
    int a, n = 0;
    scanf("%d", &a);
    while(a){
        n = a % 10;
        if(n == 9){
            printf("YES\n");
            return 0;
        }
        a /= 10;
    }
    printf("NO\n");
    return 0;
}
