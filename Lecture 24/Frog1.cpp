#include<bits/stdc++.h>
using namespace std;
// const int N = 0;
#define int long long


int solve(int i, vector<int>&v, vector<int>&dp) {
	if (i == v.size() - 1) {
		return 0;
	}

	if (dp[i] != -1) {
		return dp[i];
	}
	int option1 =  INT_MAX;
	int option2 = INT_MAX;

	option1 = abs(v[i] - v[i + 1]) + solve(i + 1, v, dp);
	if (i + 2 <= v.size() - 1) {
		option2 = abs(v[i] - v[i + 2]) + solve(i + 2, v, dp);
	}
	return dp[i] = min(option1, option2);
}

int32_t main() {
	int n;
	cin >> n;

	vector<int>v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}

	vector<int>dp(n + 1, -1);
	cout << solve(0, v, dp);
}