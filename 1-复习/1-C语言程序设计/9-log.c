/*************************************************************************
	> File Name: 9-log.c
	> Author: chenyueze
	> Mail: chen_buzhou@163.com
	> Created Time: 三  9/ 2 14:41:59 2020
 ************************************************************************/

#include<stdio.h>


#ifdef DEBUG
#define log(frm, arg...) {\
    printf("%s [%s : %s : %d] : ", __TIME__, __FILE__, __func__, __LINE__);\
    printf(frm, ##arg);\
}
#else
#define log(frm, arg...)
#endif


int main(){
    int a = 123;
    log("%d\n", a);
    log("hello world\n");
    return 0;
}
