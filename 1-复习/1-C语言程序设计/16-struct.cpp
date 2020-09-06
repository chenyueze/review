/*************************************************************************
	> File Name: 16-string.cpp
	> Author: chenyueze
	> Mail: chen_buzhou@163.com
	> Created Time: 日  9/ 6 12:50:51 2020
 ************************************************************************/
#include <stdio.h>

struct node1{
    char a;
    char b;
    int c;
};

struct node2{
    char a;
    int c;
    char b;
};

int main(){
    printf("%lu %lu\n", sizeof(node1), sizeof(node2));
    
    return 0;
}
