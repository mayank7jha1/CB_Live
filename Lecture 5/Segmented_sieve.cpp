#include<bits/stdc++.h>
using namespace std;
// const int N = 0;
#define int long long

const int N = 1000001;
vector<int>primes;
bool p[N + 10] = {0};


void Prime_seive() {
	for (int i = 3; i * i < N; i += 2) {
		if (p[i] == 0) {
			for (int j = i * i; j <= N; j += i) {
				p[j] = 1;
			}
		}
	}

	primes.push_back(2);
	for (int i = 3; i <= N; i += 2) {
		if (p[i] == 0) {
			primes.push_back(i);
		}
	}
}

void Segmented_Sieve(int a, int b) {
	bool p1[b - a + 1] = {0};

	for (int i = 0; primes[i]*primes[i] <= b; i++) {
		//Find the starting point for the prime[i] factor:
		int start = ((a / primes[i]) * primes[i]);
		if (start < a) {
			start += primes[i];
		}
		for (int j = start; j <= b; j += primes[i]) {
			p1[j - a] = 1;
		}

		//Overlap;
		if (start == primes[i]) {
			p1[start - a] = 0;
		}
	}

	for (int j = a; j <= b; j++) {
		if (p1[j - a] == 0) {
			cout << j << endl;
		}
	}
	cout << endl;
}



int32_t main() {
	Prime_seive();
	int t;
	cin >> t;
	while (t--) {
		int a, b;
		cin >> a >> b;
		if (a == 1) {
			a++;
		}
		Segmented_Sieve(a, b);
	}

}
