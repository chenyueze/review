//角度值转弧度值
#include <stdio.h>
#include <math.h>

int main(){
    const double PI = acos(-1);
    int x;
    scanf("%d", &x);
    printf("%lf\n", x * PI / 180);
    return 0;
}