#include <iostream>
using namespace std;
#define MAX_N  100000
long long h[MAX_N + 5];
long long l[MAX_N + 5], r[MAX_N + 5];
int s[MAX_N + 5], top;

int main(){
    int n;
    cin >> n;
    h[0] = h[n + 1] = -1;
    for(int i = 1; i <= n; i++) cin >> h[i];
    top = -1;
    s[++top] = 0;for(int i = 1; i <= n ; i++){
        while(h[s[top]] >= h[i]) --top;
        l[i] = i - s[top];
        s[++top] = i;
    }
    top = -1;
    s[++top] = n + 1;
    for(int i = n; i >= 1; --i){
        while(h[s[top]] >= h[i]) --top;
        r[i] = s[top] - i;
        s[++top] = i;
    }
    long long ans = 0;
    for(int i = 1; i <= n; i++){
        ans = max(ans, h[i] * (l[i] + r[i] - 1));
    }
    cout << ans << endl;
    return 0;
}