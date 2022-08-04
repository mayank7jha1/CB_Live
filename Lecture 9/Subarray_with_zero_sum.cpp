#include<bits/stdc++.h>
using namespace std;
// const int N = 0;

// check if there exists a subarray with sum 0;

bool solve(int *a, int n) {
	unordered_set<int>s;
	//unordered_map<int, int>m;

	int pre = 0;//Running Sum store

	for (int i = 0; i < n; i++) {
		pre += a[i];
		if (pre == 0 or s.find(pre) != s.end()) {
			return true;
		}
		s.insert(pre);
	}
	return false;
}

//O(NlogN);
int main() {
	int n;
	cin >> n;
	int a[n];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	cout << solve(a, n) << endl;
}