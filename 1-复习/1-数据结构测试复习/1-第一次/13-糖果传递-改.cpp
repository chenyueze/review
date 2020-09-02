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
    int avg = s[n] / n;
    for(int i = 1; i <= n; i ++){
        s[i] -= avg;
    }
    sort(s + 1, s + 1 + n);
    int val = s[(n + 1) / 2], ans = 0;
    for(int i = 1; i <= n; i++){
        ans += abs(s[i] - val);
    }
    cout << ans << endl;
    return 0;
}