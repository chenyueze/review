#include <iostream>
using namespace std;
#define MAX_N 10000
int arr[MAX_N + 5];
int buf[MAX_N + 5]; 

int main(){
    int n, num, j_n;
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> num >> j_n;
        int ans = 0, b = 0;
        for(int t = 1; t <= (j_n / 10 + 1); t++){
            int ti;
            if(t != (j_n / 10 + 1)) ti = 10;
            else ti = j_n % 10;
            for(int j = 1; j <= ti; j++){
                cin >> arr[j];
                if(j % 2 != 0){
                    ans += 1;
                    buf[ans] = arr[(j + 1) / 2];
                }
            } 
        }
        cout << num << " " << ans << endl;
        for(int j = 1; j <= ans; j++){
            cout << buf[j] << " ";
        }
        cout << endl;
    }
    return 0;
}