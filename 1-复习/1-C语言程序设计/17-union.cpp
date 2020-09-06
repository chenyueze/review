/*************************************************************************
	> File Name: 17-union.cpp
	> Author: chenyueze
	> Mail: chen_buzhou@163.com
	> Created Time: 日  9/ 6 14:55:35 2020
 ************************************************************************/
#include <stdio.h>

union IP {
    unsigned int num;
    struct {
        unsigned char a1;
        unsigned char a2;
        unsigned char a3;
        unsigned char a4;
    }ip;
};

int main(){
    union IP p;
    char str[25];
    unsigned int arr[4];
    while(~scanf("%s", str)){
        sscanf(str, "%d.%d.%d.%d", arr, arr + 1, arr + 2, arr + 3);
        p.ip.a1 = arr[0]; // arr[3]
        p.ip.a2 = arr[1]; // arr[2]
        p.ip.a3 = arr[2]; // arr[1]
        p.ip.a4 = arr[3]; // arr[0]
        printf("%u\n", p.num);
        //大端机,小端机
    }
    return 0;
}
