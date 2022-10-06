#include<bits/stdc++.h>
using namespace std;
// const int N = 0;
#define int long long

int n, m;
int a[5005], b[5005], dp[5005][5005];

int Valentine_Magic(int i, int j) {
	//i is for boys:
	if (i == n) {
		//We have iterated over all the boys:
		//We have a answer;
		return 0;
	}

	if (j == m) {
		//Matlab saari girls khatam hogyi hain before the boys
		//this scenario cannot happen
		return 1e12;//THis can never be your answer and since
		//we are taking min of all the options we will just
		//return something very large.
	}

	if (dp[i][j] != -1) {
		return dp[i][j];
	}

	int option1 = 0 + Valentine_Magic(i, j + 1);
	//Above statement means current boy decides not to
	//choose the current girl
	//current girl will not make pair with any boy

	int option2 = abs(a[i] - b[j]) + Valentine_Magic(i + 1, j + 1);
	//Current boy makes pair with current girl

	//int option3 = Valentine_Magic(i + 1, j);
	//Above statement means the current girl deciddes
	//not to choose the current boy which is not possible

	return dp[i][j] = min(option1, option2);

}

int32_t main() {
	cin >> n >> m;
	memset(dp, -1, sizeof(dp));

	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	for (int i = 0; i < m; i++) {
		cin >> b[i];
	}
	sort(a, a + n);
	sort(b, b + m);
	int ans = Valentine_Magic(0, 0);
	cout << ans << endl;
}