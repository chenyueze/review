/*************************************************************************
	> File Name: 14-prime.cpp
	> Author: chenyueze
	> Mail: chen_buzhou@163.com
	> Created Time: 五  9/ 4 19:15:24 2020
 ************************************************************************/
#include <stdio.h>
#define MAX_N 1000

int prime[MAX_N + 5] = {0};

void init_prime(){
    prime[0] = 1, prime[1] = 1;
    for(int i = 2; i <= MAX_N; i++){
        if(prime[i] == 1) continue;
        for(int j = i * i; j <= MAX_N; j += i){
            prime[j] = 1;
        }
    }
}

int main(){
    init_prime();
    int n; 
    scanf("%d", &n);
    printf("%s\n", prime[n] ? "NO" : "YES");
    return 0;
}
