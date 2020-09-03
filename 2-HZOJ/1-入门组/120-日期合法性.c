/*************************************************************************
	> File Name: 120-日期合法性.c
	> Author: chenyueze
	> Mail: chen_buzhou@163.com
	> Created Time: 三  9/ 2 18:14:05 2020
 ************************************************************************/

#include<stdio.h>

int days[15] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int isYear(int y){
    return ((y % 4 == 0 && y % 100 != 0) || y % 400 == 0);
}

int isVal(int y, int m, int d){
    if(y <= 0 || m <= 0 || m > 12 || d <= 0 || d > 31) return 0;

    if(m == 2 && (d <= (days[m] + isYear(y)))) return 1;
    else if(d > days[m]) return 0;
    return 1;
}

int main(){
    int y, m, d;
    scanf("%d%d%d", &y, &m, &d);
    if(isVal(y, m, d)){
        printf("YES\n");
        return 0;
    }else{
        printf("NO\n");
        return 0;
    }
}
