#include<bits/stdc++.h>
using namespace std;
#define int long long


int32_t main() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		int a[n];
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		int pre[100005] = {0};
		pre[0] = a[0];

		for (int i = 1; i < n; i++) {
			pre[i] = pre[i - 1] + a[i];
		}

		// for (int i = 0; i < n; i++) {
		// 	cout << pre[i] << " ";
		// }
		// cout << endl;

		for (int i = 0; i < n; i++) {
			pre[i] = pre[i] % n;
			pre[i] = (pre[i] + n) % n;
		}

		// for (int i = 0; i < n; i++) {
		// 	cout << pre[i] << " ";
		// }

		int freq[100005] = {0};
		freq[0] = 1;//For the very first element.

		for (int i = 0; i < n; i++) {
			freq[pre[i]]++;
		}
		//cout << endl;
		int ans = 0;

		for (int i = 0; i < 100005; i++) {
			if (freq[i] > 1) {
				ans += (freq[i] * (freq[i] - 1)) / 2;
			}
		}
		cout << ans << endl;

	}
}


