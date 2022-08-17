#include<bits/stdc++.h>
using namespace std;

int Solve(int *a, int n, int k) {

	if (n <= 0) {
		return 0;
	}

	int ans = INT_MAX;
	for (int i = 1; i <= k; i++) {
		if (n - i < 0) {
			break;
		}
		int value = Solve(a, n - i, k);
		ans = min(ans, abs(a[n] - a[n - i]) + value);
	}
	return ans;
}





int main() {
	int n;
	cin >> n;
	int k;
	cin >> k;
	int a[n];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}


	cout << Solve(a, n - 1, k) << endl;
}