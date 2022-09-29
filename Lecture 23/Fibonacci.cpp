#include<bits/stdc++.h>
using namespace std;
// const int N = 0;

int dp[10005];

int fib(int n) {
	if (n <= 1) {
		return n;
	}

	if (dp[n] != -1) {
		return dp[n];
	}

	int option1 = fib(n - 1);
	int option2 = fib(n - 2);

	return dp[n] = option1 + option2;
}

int main() {
	int n;
	cin >> n;
	memset(dp, -1, sizeof(dp));
	cout << fib(n) << endl;
}