#include <iostream>
using namespace std;
#define MAX_N 100000
int arr[MAX_N + 5];

int main(){
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> arr[i];
    int sum = 0;
    sort(arr + 1, arr + 1 + n);
    int x = arr[(1 + n) / 2];
    for(int i = 1; i <= n; i++) sum += abs(arr[i] - x);
    cout << sum << endl;
    return 0;
}