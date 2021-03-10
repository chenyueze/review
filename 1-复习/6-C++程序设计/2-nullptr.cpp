/*************************************************************************
	> File Name: 2-nullptr.cpp
	> Author: chenyueze
	> Mail: chen_buzhou@163.com
	> Created Time: 日  9/27 13:12:57 2020
 ************************************************************************/

#include<iostream>
using namespace std;

void f(int n){
    cout << n << endl;
}

void f(int *p){
    cout << p << endl;
}

int main(){
    f(0);
    f(nullptr);
    return 0;
}
