#include<bits/stdc++.h>
using namespace std;
// const int N = 0;

const int N = 100100;
int a[N];
int b[N];

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;

		for (int i = 1; i <= n; i++) {
			char ch;
			cin >> ch;
			a[i] = '9' - ch;
		}

		// for (int i = 1; i <= n; i++) {
		// 	cout << a[i] << " ";
		// }
		// cout << endl;

		if (a[1] != 0) {
			for (int i = 1; i <= n; i++) {
				cout << a[i];
			}
			cout << endl;
		} else {
			for (int i = 1; i <= n - 1; i++) {
				b[i] = 1;
			}
			b[n] = 2;
			for (int i = n; i >= 1; i--) {
				b[i] = a[i] + b[i];
				if (b[i] >= 10) {
					b[i] -= 10;
					b[i - 1]++;
				}
			}
			for (int i = 1; i <= n; i++) {
				cout << b[i];
			}
			cout << endl;
		}

	}

}



// 9 8 8 8 4

// 0 1 1 1 5
// 1 1 1 1 2

// 1 1 1 1 1 1