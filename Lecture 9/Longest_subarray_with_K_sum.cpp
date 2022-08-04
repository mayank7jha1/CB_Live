#include<bits/stdc++.h>
using namespace std;
// const int N = 0;

int solve(int *a, int n, int k) {
	unordered_map<int, int>m;
	int pre = 0;
	int len = 0;

	for (int i = 0; i < n; i++) {
		pre += a[i];
		if (pre == k) {
			len = max(len, i + 1);
		}
		if (m.find(pre - k) != m.end()) {
			len = max(len, i - m[pre - k]);
		} else {
			m[pre] = i;
		}
	}
	return len;
}

int main() {
	int n;
	cin >> n;
	int a[n];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	int k;
	cin >> k;

	cout << solve(a, n, k) << endl;
}