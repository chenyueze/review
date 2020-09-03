/*************************************************************************
	> File Name: 122-时间转换.c
	> Author: chenyueze
	> Mail: chen_buzhou@163.com
	> Created Time: 三  9/ 2 18:57:11 2020
 ************************************************************************/

#include<stdio.h>

int main(){
    int t;
    scanf("%d", &t);
    if(t < 43200){
        printf("%02d:%02d:%02d am\n", t / 3600, t % 3600 / 60, t % 60);
    }else if(t < 43200 + 3600){
        printf("%02d:%02d:%02d midnoon\n", t / 3600, t % 3600 / 60, t % 60);
    }else{
        t -= 43200;
        printf("%02d:%02d:%02d pm\n", t / 3600, t % 3600 / 60, t % 60);
    }
    return 0;
}
