#include<bits/stdc++.h>
using namespace std;
// const int N = 0;
int dp[100005];
int a, b;
int k;
int pre[100005];
#define mod 1000000007
#define int long long

int Flowers(int len, int k) {
	if (len == 0) {
		//That means you have found a way to reach the last
		//bucket that means you have found an answer or a way:
		return 1;
	}
	if (dp[len] != -1) {
		return dp[len];
	}
	int option1 = Flowers(len - 1, k);//Red flower at the current index:
	int option2 = 0;
	if (len >= k) {
		option2 = Flowers(len - k, k);//White Flower at the current index:
	}
	return dp[len] = option1 + option2;
}

void precompute() {
	memset(dp, -1, sizeof(dp));
	pre[0] = 0;

	for (int i = 1; i < 10005; i++) {
		pre[i] = pre[i - 1] + Flowers(i, k);
		pre[i] = pre[i] % mod;
	}
}

int32_t main() {
	int t;
	cin >> t >> k;
	precompute();//O(N)

	while (t--) {
		cin >> a >> b;
		//memset(dp, -1, sizeof(dp));
		/*int ans = 0;
		for (int i = a; i <= b; i++) {
			ans = ans + Flowers(i, k);
		}
		cout << ans << endl;*/
		cout << (pre[b] - pre[a - 1] + mod) % mod << endl;
	}
}


// dp[3]= ka answer:

// pre[array];; 3 tak ka answer;


