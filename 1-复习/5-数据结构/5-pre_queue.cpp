/*************************************************************************
	> File Name: 5-pre_queue.cpp
	> Author: chenyueze
	> Mail: chen_buzhou@163.com
	> Created Time: 二  9/15 08:36:49 2020
 ************************************************************************/

#include<iostream>
using namespace std;
#define MAX_N 300000
int a[MAX_N];
int q[MAX_N], head = 0, tail = 0;

int main(){
    int n, k;
    cin >> n >> k;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    for(int i = 1; i <= n; i++){
        while(tail - head && a[q[tail - 1]] >= a[i]) tail--;
        q[tail++] = i;
        if(q[head] <= i - k) head++;
        if(i < k) continue;
        i == k || cout << " ";
        cout << a[q[head]];
    }
    cout << endl;
    head = tail = 0;
    for(int i = 1; i <= n; i++){
        while(tail - head && a[q[tail - 1]] <= a[i]) tail--;
        q[tail++] = i;
        if(q[head] <= i - k) head++;
        if(i < k) continue;
        i == k || cout << " ";
        cout << a[q[head]];
    }
    cout << endl;
    return 0;
}
