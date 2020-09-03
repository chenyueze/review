/*************************************************************************
	> File Name: 10-max_int.c
	> Author: chenyueze
	> Mail: chen_buzhou@163.com
	> Created Time: 三  9/ 2 20:58:46 2020
 ************************************************************************/
#include <stdarg.h>
#include <inttypes.h>
#include<stdio.h>

#define P(func) {\
    printf("%s : %d\n", #func, func);\
}

int max_int(int n, ...){
    int ans = INT32_MIN;
    int temp;
    va_list arg;
    va_start(arg, n);
    while(n--){
        temp = va_arg(arg, int);
        temp > ans && (ans = temp); 
    }
    va_end(arg);
    return ans;
}

int main(){
    P( max_int(4, 1, 2, 3, 4));
    P( max_int(3, 17, 21, 4));
    P( max_int(2, 31, 24));
    P( max_int(5, 11, 42, 63, 34, 24));
    P( max_int(4, 4, 3, 2, 1));

    return 0;
}
