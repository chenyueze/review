#include <iostream>
using namespace std;

int val[25], dp[25][10005];

int main() {
	int m, n;
	cin >> m >> n;
	for (int i = 1; i <= m; i++) {
		cin >> val[i];
	}
	for (int i = 1; i <= m; i++) {
		dp[i][0] = 1;
		for (int j = 1; j <= n; j++) {
			dp[i][j] = dp[i - 1][j];
			if (val[i] <= j) dp[i][j] += dp[i][j - val[i]];
			dp[i][j] %= 9973;
		}
	}
	cout << dp[m][n] << endl;
	return 0;
}