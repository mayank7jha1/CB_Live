#include<bits/stdc++.h>
using namespace std;
// const int N = 0;
#define int long long
int n, m;
int dp[1001][1001] = {0};

int Solve() {
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		dp[x][y]++;
	}


	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			//Prefix of Every Row:
			dp[i][j] = dp[i][j] + dp[i][j - 1];
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			//Prefix of Every Col.:
			dp[i][j] = dp[i][j] + dp[i - 1][j];
		}
	}


	int ans = INT_MIN;

	for (int i = 1; i < n; i++) {
		for (int j = 1; j < n; j++) {

			int op1 = dp[i][j];
			int op2 = dp[n][j] - dp[i][j];
			int op3 = dp[i][n] - dp[i][j];
			int op4 = dp[n][n] - op1 - op2 - op3;

			ans = max(ans, min({op1, op2, op3, op4}));
		}
	}
	cout << ans << endl;

}


int32_t main() {
	Solve();
}