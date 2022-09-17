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
	// if (__gcd(a, m) != 1) {
	// 	return 0;
	// }

	EED(a, m);
	return (x + m) % m;
}


int32_t main() {
	int n, p, w, d;
	cin >> n >> p >> w >> d;

	int x, y, z;
	int g = __gcd(w, d);

	if (p % g != 0) {
		cout << "-1" << endl;
		return 0;
	}

	//If he wins all his matches:

	if (n * w < p) {
		cout << "-1" << endl;
		return 0;
	}

	p = p / g;//p=p'
	w = w / g;//w'
	d = d / g;

	//Y ka solution find karo:

	y = ((p % w) * inverseModulo(d, w)) % w;

	x = (p - y * d) / w;

	if (x + y > n) {
		cout << "-1" << endl;
		return 0;
	}
	if (x < 0) {
		cout << "-1" << endl;
		return 0;
	}

	z = n - (x + y);

	cout << x << " " << y << " " << z << endl;


}