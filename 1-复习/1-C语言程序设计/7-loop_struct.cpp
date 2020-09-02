/*************************************************************************
	> File Name: 7-loop_struct.cpp
	> Author: 
	> Mail: 
	> Created Time: 二  9/ 1 14:57:24 2020
 ************************************************************************/

#include<iostream>
using namespace std;

int main(){
    int n;
    scanf("%d", &n);
    int digits = 0;
    /*while(n){
        n /= 10;
        digits += 1;
    }

    不能判断0有几位*/
    
    do{
        n /= 10;
        digits += 1;
    } while (n);

    printf("%d\n", digits);

    return 0;
}
