/*************************************************************************
	> File Name: 14-my_printf.cpp
	> Author: chenyueze
	> Mail: chen_buzhou@163.com
	> Created Time: 五  9/ 4 16:22:15 2020
 ************************************************************************/

#include <stdio.h>
#include <stdarg.h>

#define PUTC(a) putchar(a), ++cnt

int my_printf(const char *frm, ...){
    va_list arg;
    va_start(arg, frm);
    int cnt = 0;
    for(int i = 0; frm[i]; i++){
        switch(frm[i]){
            case '%' : {
                switch(frm[++i]){
                    case 'd' : {
                        int x = va_arg(arg, int), temp = 0, digit = 0;
                        if(x < 0) PUTC('-'), x = -x;
                        do{
                            temp = temp * 10 + x % 10;
                            x /= 10;
                            digit += 1;
                        }while(x);
                        while(digit){
                            PUTC(temp % 10 + '0');
                            temp /= 10;
                        }
                    }break;
                    case '%' : {
                        PUTC(frm[i]);
                    }break;
                }
            }break;
            default : PUTC(frm[i]); break;
        }
    }
    va_end(arg);
    return cnt;
}

int main(){
    int a = 123;
    printf("hello world!\n");
    my_printf("hello world\n");
    printf("int (a) = %d\n", a);
    my_printf("int (a) = %d\n", a);
    return 0;
}

