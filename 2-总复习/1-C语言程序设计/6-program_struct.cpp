/*************************************************************************
	> File Name: 6-program_struct.cpp
	> Author: 
	> Mail: 
	> Created Time: 二  9/ 1 14:26:31 2020
 ************************************************************************/

#include<iostream>
#include <ctime>
#include <cstdlib>
using namespace std;


int main(){
    srand(time(0));
    int a, b;
    scanf("%d%d", &a, &b);
    if(a - b){
        printf("not equal\n");
    }else{
        printf("equal\n");
    }

    if((a++) && (b++)){
        printf("true\n");
    }else{
        printf("false\n");
    }
    
    if((a++) || (b++)){
        printf("true\n");
    }else{
        printf("false\n");
    }
    cout << "a = " << a << ", b = " << b << endl;

    for(int i = 0; i < 10; i++){
        i && printf(" "); // 更高效
        printf("%d", i);
        //printf("%d ", i);
    }
    
    int cnt = 0;
    for(int i = 0; i < 10; i ++){
        int val = rand() % 100;
        //if(val % 2 == 1) cnt += 1;
        //cnt += val % 2;
        cnt += val & 1;
        //i && printf(" ");
        i == 0 || printf(" ");
        printf("%d", val);

    }
    printf("odd numbers = %d\n", cnt);
    return 0;
}
