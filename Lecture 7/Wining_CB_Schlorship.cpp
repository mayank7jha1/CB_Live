#include<bits/stdc++.h>
using namespace std;
// const int N = 0;
#define int long long

bool check(int mid, int n, int m, int x, int y) {
	int Total_Number_Coupons_That_We_Have = m + (n - mid) * y;

	int Total_Number_Coupons_That_We_Need = x * mid;

	if (Total_Number_Coupons_That_We_Have >= Total_Number_Coupons_That_We_Need) {
		return true;
	} else {
		return false;
	}
}

int32_t main() {
	int n, m, x, y;
	cin >> n >> m >> x >> y;
	int s = 0, e = n;
	int ans = 0;

	while (s <= e) {
		int mid = (s + e) / 2;
		if (check(mid, n, m, x, y)) {
			ans = mid;
			s = mid + 1;
		} else {
			e = mid - 1;
		}
	}
	cout << ans << endl;
}