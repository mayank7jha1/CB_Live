#include<bits/stdc++.h>
using namespace std;
// const int N = 0;
#define int long long
int x, y, GCD;

void EED(int a, int b) {
	//Base Case:
	if (b == 0) {
		x = 1, y = 0;
		GCD = a;
		return;
	}

	EED(b, a % b);

	int current_x = y;
	int current_y = x - ((a / b) * y);

	x = current_x;
	y = current_y;
}


int inverseModulo(int a, int m) {
	if (__gcd(a, m) != 1) {
		return 0;
	}

	EED(a, m);
	return (x + m) % m;
}

int32_t main() {
	int a = 30, b = 18;
	EED(a, b);
	cout << x << " " << y << endl;
	cout << inverseModulo(6, 7) << endl;
}
