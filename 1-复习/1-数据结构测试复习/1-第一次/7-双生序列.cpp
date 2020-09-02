#include <iostream>
using namespace std;
#define MAX_N  500000
int a[MAX_N + 5], b[MAX_N + 5];
int top1 = -1, top2 = -1;

int main(){
    int n, p = 0;
    cin >> n;
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < n; i++) cin >> b[i];
    while(p < n){
        while(top1 != -1 && a[top1] > a[p]) top1--;
        while(top2 != -1 && b[top2] > b[p]) top2--;
        if(top1 != top2) break;
        a[++top1] = a[p];
        b[++top2] = b[p];
        p += 1;
    }
    cout << p << endl;
    return 0;
}