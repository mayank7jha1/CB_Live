#include<bits/stdc++.h>
using namespace std;
// const int N = 0;
//bool p[100000005] = {0};//A global array tum 10^8 banaoge tumhe issues aayenge.

// bool p[100]=100*8=800 bytes consume horahe hain.10^8*8

// 1 ya 0
// array :  vector : bitset // bits ko store karta hain.
bitset<100000005>p;//10^8;  8 times faster bana diya.


void Prime_seive(int n) {
	for (int i = 3; i * i < n; i += 2) {
		if (p[i] == 0) {
			for (int j = i * i; j <= n; j += i) {
				p[j] = 1;
			}
		}
	}
	cout << 2 << " ";
	for (int i = 3; i <= n; i += 2) {
		if (p[i] == 0) {
			cout << i << " ";
		}
	}
}

int main() {
	int n;
	cin >> n;
	Prime_seive(n);
}


// this number: 10^12+10 is this a prime number or not?