#include <stdio.h>
#define PI 3.14

int main(){
    double r, h;
    scanf("%lf%lf", &r, &h);
    printf("%.2lf\n", r * r * PI);
    printf("%.2lf\n", r * r * PI * h);
    return 0;
}