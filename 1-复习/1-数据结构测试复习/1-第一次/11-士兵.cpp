#include <iostream>
#include <algorithm>
using namespace std;
#define MAX_N 10000
long long  x[MAX_N + 5], y[MAX_N + 5];
int n;

int main(){
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> x[i] >> y[i];
    sort(x + 1, x + 1 + n);
    sort(y + 1, y + 1 + n);
    for(int i = 1; i <= n; i++) x[i] -= i;
    sort(x + 1, x + 1 + n);
    long long  tx = x[(n + 1) / 2], ty = y[(n + 1) / 2];
    long long  sum = 0;
    for(int i = 1; i <= n; i++){
        sum += abs(y[i] - ty);
        sum += abs(x[i] - tx);
    }
    cout << sum << endl;
    return 0;
}