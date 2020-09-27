/*************************************************************************
	> File Name: 1-my_rand.cpp
	> Author: chenyueze
	> Mail: chen_buzhou@163.com
	> Created Time: 日  9/27 12:48:19 2020
 ************************************************************************/

#include<iostream>
using namespace std;

int my_seed = 1;

void my_srand(int seed){
    my_seed = seed;
}

int my_rand(){
    my_seed = my_seed * 3 % 101;
    return my_seed;
}


int main(){
    int arr[105] = {0};
    for(int i = 0; i < 100; ++i){
        int temp = my_rand();
        arr[temp] += 1;
        cout << temp << " ";
    }
    cout << endl;
    for(int i = 1; i < 101; ++i){
        cout << arr[i] << " " ;
    }
    cout << endl;

    return 0;
}
