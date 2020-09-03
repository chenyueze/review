/*************************************************************************
	> File Name: 117-回文数.c
	> Author: chenyueze
	> Mail: chen_buzhou@163.com
	> Created Time: 三  9/ 2 16:41:40 2020
 ************************************************************************/

#include<stdio.h>

int main(){
    int n, temp = 0, ans = 0;
    scanf("%d", &n);
    temp = n;
    while(temp){
        ans *= 10;
        ans += temp % 10;
        temp /= 10;
    }
    if(ans == n) printf("YES\n");
    else printf("NO\n");
    return 0;
}
