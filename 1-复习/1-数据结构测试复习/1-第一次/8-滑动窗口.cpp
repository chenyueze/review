#include <iostream>
using namespace std;
#define MAX_N 300000
int arr[MAX_N + 5];
int q[MAX_N + 5];
int head, tail;

int main(){
    int n, k;
    cin >> n >> k;
    for(int i = 0; i < n; i++) cin >> arr[i];
    head = tail = 0;
    for(int i = 0; i < n; i++){
        while(tail - head != 0 && arr[q[tail - 1]] >= arr[i]) tail--;
        q[tail++] = i;
        if(i - q[head] >= k) head++;
        if(i + 1 >= k){
            i + 1 == k || cout << " ";
            cout << arr[q[head]];
        }
    }
    cout << endl;
    head = tail = 0;
    for(int i = 0; i < n; i++){
        while(tail - head && arr[q[tail - 1]] <= arr[i]) tail--;
        q[tail++] = i;
        if(i - q[head] >= k) head ++;
        if(i + 1 >= k) {
            i + 1 == k || cout << " ";
            cout << arr[q[head]];
        }
    }
    return 0;
}