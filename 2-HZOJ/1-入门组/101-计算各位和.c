#include <stdio.h>

int main(){
    int n;
    scanf("%d", &n);
    int a = 0;
    while(n){
        a += n % 10;
        n /= 10;
    }
    printf("%d\n", a);
    return 0;
}