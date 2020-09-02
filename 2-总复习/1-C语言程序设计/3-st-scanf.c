#include <stdio.h>

int main(){
    char str[100];
    while(scanf("%[^\n]s", str)){
        getchar();
        printf("%s\n", str);
    }
}