#include <stdio.h>

int main(){
    int a, b = 0;
    scanf("%d", &a);
    b += a % 10 * 10;
    b += a / 10;
    printf("%d\n", b);
    return 0;
}