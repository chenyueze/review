/*************************************************************************
	> File Name: 119-昨天和明天.c
	> Author: chenyueze
	> Mail: chen_buzhou@163.com
	> Created Time: 三  9/ 2 17:00:33 2020
 ************************************************************************/
#include <stdio.h>

int days[] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
void yesterday(int y, int m, int d){
    d -= 1;
    if(d == 0){
        m = m - 1;
        if(m == 0){
            y -= 1;
            m = 12;
        }
        d = days[m] + ((m == 2) && ((y % 4 == 0 && y % 100 != 0) || (y % 400 == 0)));
    }
    printf("%d %d %d\n",y, m, d);
    return;
}
void nextday(int y, int m, int d){
    d = d + 1;
    if(d > (days[m] + ((m == 2) && ((y % 4 == 0 && y % 100 != 0) || (y % 400 == 0))))){
        m = m + 1;
        if(m > 12){
            y = y + 1;
            m = 1;
        }
        d = 1;
    }
    printf("%d %d %d\n",y, m, d);
    return;
}
int main() {
    int y, m, d;
    scanf("%d %d %d",&y, &m, &d);
    yesterday(y, m, d);
    nextday(y, m, d);
    return 0;
}


