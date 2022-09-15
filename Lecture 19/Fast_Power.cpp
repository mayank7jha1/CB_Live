#include<bits/stdc++.h>
using namespace std;
// const int N = 0;
#define int long long

int fast_power_using_recursion(int a, int b) {
	if (b == 0) {
		return 1;
	}
	int x = fast_power_using_recursion(a, b / 2);
	if (b & 1) {
		return a * x * x;
	}
	return x * x;
}

int fast_power_using_bitmask(int a, int b) {
	int result = 1;
	while (b > 0) {
		if (b & 1) {
			result = result * a;
		}
		a = a * a;
		b = b >> 1;
	}
	return result;
}


int fast_power_using_bitmask_and_modulus(int a, int b, int m) {
	int result = 1;
	while (b > 0) {
		if (b & 1) {
			result = (((result % m) * (a % m)) % m);
		}
		a = ((a % m) * (a % m)) % m;
		b = b >> 1;
	}
	return result;
}

int32_t main() {
	int a, b;
	cin >> a >> b;
	cout << fast_power_using_recursion(a, b) << endl;
	cout << fast_power_using_bitmask(a, b) << endl;
	cout << fast_power_using_bitmask_and_modulus(a, b, 100);
}

//Every odd Number will have the last bit as 1.
//Jab tum bits ke sath deal karte ho to &.



(2 ^ 8) % 100 = 56