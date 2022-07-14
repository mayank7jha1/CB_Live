#include<bits/stdc++.h>
using namespace std;
// const int N = 0;
#define int long long
//int pre[100005] = {0};
//int a[100005] = {0};
//int freq[100005] = {0};

int32_t main() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		int a[n];
		int freq[100005] = {0};
		int sum = 0;
		freq[0] = 1;
		for (int i = 0; i < n; i++) {
			cin >> a[i];
			sum += a[i];//Prefix array ka kaam kar raha hu.

			sum = sum % n;
			sum = (sum + n) % n;//Prefix array ka mod;
			freq[sum]++;//Prefix array elements which are same.
		}
		int ans = 0;

		for (int i = 0; i < n; i++) {
			int value = freq[i];
			ans += (value * (value - 1)) / 2;
		}
		cout << ans << endl;
	}
}

// nC2 == = n * (n - 1) / 2;



// (a - b) % n;

// a % n - b % n == -ve:

// ((a % n - b % n) + n) % n;===This thing will always be positive;