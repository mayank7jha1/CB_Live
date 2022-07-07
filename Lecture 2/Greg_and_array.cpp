#include<bits/stdc++.h>
using namespace std;
// const int N = 0;
#define ll long long
#define size 10005

int main() {
	ll n, m, k;
	cin >> n >> m >> k;
	ll a[n + 1] = {0};
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}

	ll l[size], r[size], d[size];
	for (int i = 1; i <= m; i++) {
		cin >> l[i] >> r[i] >> d[i];
	}

	ll operations_count[size] = {0};

	for (int i = 0; i < k; i++) {
		ll x, y;
		cin >> x >> y;
		operations_count[x] += 1;
		operations_count[y + 1] -= 1;
	}

	//Prefix Sum:

	for (int i = 1; i <= m; i++) {
		operations_count[i] = operations_count[i - 1] + operations_count[i];
	}

	ll total_operations_sum[size] = {0};

	for (int i = 1; i <= n; i++) {
		total_operations_sum[l[i]] = total_operations_sum[l[i]] + operations_count[i] * d[i];
		total_operations_sum[r[i] + 1] = total_operations_sum[r[i] + 1] - operations_count[i] * d[i];

	}

	//Prefix Sum of the total_operations_count

	for (int i = 1; i <= n; i++) {
		total_operations_sum[i] = total_operations_sum[i - 1] + total_operations_sum[i];
	}

	for (int i = 1; i <= n; i++) {
		a[i] = total_operations_sum[i] + a[i];
	}
	for (int i = 1; i <= n; i++) {
		cout << a[i] << " ";
	}
}


