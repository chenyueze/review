/*************************************************************************
	> File Name: 18-pointer.cpp
	> Author: chenyueze
	> Mail: chen_buzhou@163.com
	> Created Time: 日  9/ 6 17:59:34 2020
 ************************************************************************/
#include <stdio.h>

#define offset(T, a) ({\
    T tmp;\
    (char *)(&tmp.a) - (char *)(&tmp);\
})


struct Data{
    double a;
    int b;
    char c;
};

int main(int arg, char *argv[], char *env[]){
    int num1 = 0x616263;
    int num2 = 0x61626364;
    printf("%s\n", (char *)(&num1));
    printf("%s\n", (char *)(&num2));
    printf("%s\n", (char *)(&num2 + 1));
    printf("%ld\n", offset(struct Data, a));
    for(int i = 0; i < arg; i ++){
        printf("argv[%d] = %s\n", i, argv[i]);
    }
    for(int i = 0; env[i]; i++){
        printf("env[%d] = %s\n", i, env[i]);
    }
    return 0;
}
