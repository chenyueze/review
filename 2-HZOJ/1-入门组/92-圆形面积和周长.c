#include <stdio.h>
#define PI 3.14

int main(){
    double r;
    scanf("%lf", &r);
    double measure = PI * r * r;
    double perimeter = 2 * PI * r;
    printf("%.2f\n", perimeter);
    printf("%.2lf\n", measure);
    return 0;
}