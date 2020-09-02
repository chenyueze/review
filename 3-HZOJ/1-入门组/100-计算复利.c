#include <stdio.h>
#define rate 1.00417

int main(){
    int n;
    double a = 0;
    scanf("%d", &n);
    for(int i = 0; i < 6; i++){
        a += n; 
        a *= rate;
    } 
    printf("$%.2lf", a);
    return 0;
}