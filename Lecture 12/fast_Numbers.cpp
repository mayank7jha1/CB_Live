#include<bits/stdc++.h>
using namespace std;
// const int N = 0;
#define int long long


int fast_power_using_recursion(int a, int b) {
	if (b == 0) {
		return 1;
	}

	int x = fast_power_using_recursion(a, b / 2);

	/*2 ^ 11: 2 ^ 5: 32
	2 ^ 11 = 32 * 32 * 2;*/

	if (b % 2 == 1) {
		return a * x * x;
	}

	/*	2^10: 2^5: 32
		32*32*/

	return x * x;
}

int32_t main() {
	int x, y;
	cin >> x >> y;
	cout << fast_power_using_recursion(2, 11);
}