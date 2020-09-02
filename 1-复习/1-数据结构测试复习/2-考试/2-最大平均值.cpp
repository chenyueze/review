#include <iostream>
using namespace std;
#define MAX_N 100000
#define INF 0x3f3f3f3f

long long  n, m, arr[MAX_N + 5], b[MAX_N + 5], sum[MAX_N + 5];

bool check(long long x) {
	for (long long i = 1; i <= n; i++) {
		b[i] = arr[i] - x;
		sum[i] = b[i] + sum[i - 1];
	}
	long long y = 0;
	for (long long i = m; i <= n; i++) {
		y = min(y, sum[i - m]);
		if (sum[i] - y >= 0) return true;
	}
	return false;
}

long long bs (long long l, long long r) {
	if (l == r) return l;
	long long mid = (l + r + 1) / 2;
	if (check(mid)) return bs(mid , r);
	return bs(l, mid - 1);
}

int main() {
	cin >> n >> m;
	long long l = INF, r = -INF;
	for (long long i = 1; i <= n; i++) {
		cin >> arr[i];
		arr[i] *= 1000;
		l = min(l, arr[i]);
		r = max(r, arr[i]);
	}
	cout << bs(l ,r) << endl;
	return 0;
}