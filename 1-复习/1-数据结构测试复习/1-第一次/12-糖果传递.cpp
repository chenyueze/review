#include <iostream>
using namespace std;
#define MAX_N 1000000
long long  arr[MAX_N + 5];
long long  s[MAX_N + 5], f[MAX_N + 5];
long long  n;

int main(){
    cin >> n;
    s[0] = 0;
    for(long long  i = 1; i <= n; i ++){
        cin >> arr[i];
        s[i] = s[i - 1] + arr[i];
    }
    for(long long  i = 1; i <= n; i ++) {
        f[i] = s[i] - i * (s[n] / n);
    }
    sort(f + 1, f + 1 + n);
    long long  tf = f[(n + 1) / 2];
    long long  cost = 0;
    for(long long  i = 1; i <= n; i ++){
        cost += abs(f[i] - tf);
    }
    cout << cost << endl;
    return 0;
}