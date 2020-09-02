#include <iostream>
using namespace std;
#define MAX_N 100000
long long  x[MAX_N + 5], y[MAX_N + 5];
long long  sum[MAX_N + 5];
long long  n, m, c;


long long  solve(long long  *arr, long long  n, long long  avg){
    for(long long  i = 1; i <= n; i++){
        sum[i] = sum[i - 1] + arr[i] - avg;
    }
    sort(sum + 1, sum + n + 1);
    long long  val = sum[(n + 1) / 2], ans = 0;
    for(long long  i = 1; i <= n; i ++){
        ans += abs(sum[i] - val);
    }
    return ans;
}

int main(){
    cin >> n >> m >> c;
    long long  a, b;
    sum[0] = 0;
    for(long long  i = 1; i <= c; i ++){
        cin >> a >> b;
        x[a] += 1;
        y[b] += 1;
    }
    long long  ans = 0;
    if(c % n == 0 && c % m == 0){
        ans = solve(x, n, c / n) + solve(y, m, c / m);
        cout << "both " << ans << endl;
    }else if(c % n == 0){
        ans = solve(x, n, c / n);
        cout << "row " << ans << endl;
    }else if(c % m == 0){
        ans = solve(y, m, c / m);
        cout << "column "<< ans << endl;
    }else {
        cout << "impossible" << endl;
    }
    return 0;
}