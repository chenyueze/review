/*************************************************************************
	> File Name: 118-生肖.c
	> Author: chenyueze
	> Mail: chen_buzhou@163.com
	> Created Time: 三  9/ 2 16:45:46 2020
 ************************************************************************/

#include<stdio.h>

int sub(int a, int b){
    int ans = a >= b ? (a - b) % 12 : (12 - (b - a) % 12);
    return ans;
}

int main(){
   char *num[15] = {"rat", "ox", "tiger", "rabbit", "dragon", "snake", "horse"
                    , "sheep", "monkey", "rooster", "dog", "pig"};
    int year;
    scanf("%d", &year);
    printf("%s\n", num[((year - 1900) % 12 + 12) % 12]);
    return 0;
}
