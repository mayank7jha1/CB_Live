// Created by Mayank

#include <bits/stdc++.h>
using namespace std;
#define int long long
int k;
int sum[1000002] = {0};
string a;
void solve() {

	int s = 0, ans = 0;
	sum[0] = 1;
	for (int i = 0; i < a.length(); i++) {
		s += a[i] - '0';
		if (s >= k) {
			ans += sum[s - k];
		}
		sum[s]++;
	}
	for (int i = 0; i < 10; i++) {
		cout << sum[i] << " ";
	}
	cout << endl;
	cout << ans << endl;

}
int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> k;
	cin >> a;
	solve();
	return 0;
}
