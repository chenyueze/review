#include <stdio.h>

int main(){
    double v, a;
    scanf("%lf %lf", &v, &a);
    printf("%.2lf\n", (v * v) / (2 * a));

    return 0;
}