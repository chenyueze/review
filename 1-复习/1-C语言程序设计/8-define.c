/*************************************************************************
	> File Name: 8-define.c
	> Author: chenyueze
	> Mail: chen_buzhou@163.com
	> Created Time: 三  9/ 2 11:22:57 2020
 ************************************************************************/

#include<stdio.h>

#define P(func) { \
    printf("%s = %d\n", #func, func); \
}

#define MAX(a, b) ({ \
    __typeof(a) __a = (a); \
    __typeof(b) __b = (b); \
    __a > __b ? __a : __b; \
})


int main(){
    /*
    printf(__DATE__);
    printf("\n");
    printf(__TIME__);
    printf("\n");
    printf(__FILE__);
    printf("\n");
    printf("%d\n", __LINE__);
    //printf(__FUNC__);
    printf(__func__);
    printf("\n");
    printf(__PRETTY_FUNCTION__);
    printf("\n");
    */
    int a = 7;
    
    P(MAX(2, 3));
    P(5 + MAX(2, 3));
    P(MAX(2, MAX(3, 4)));
    P(MAX(2, 3 > 4 ? 3 : 4));
    P(MAX(a++, 6));
    P(a);
    return 0;
}
