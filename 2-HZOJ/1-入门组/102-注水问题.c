#include <stdio.h>

int main(){
    int a, b, c, t;
    double va, vb, vc, v, tt;
    scanf("%d%d%d%d", &a, & b, &c, &t);
    va = 1.0 / a;
    vb = 1.0 / b;
    vc = 1.0 / c;
    v = 1 - (va + vb) * t;
    tt = v / (va + vb - vc);
    printf("%.2lf", tt + t);
    return 0;
}