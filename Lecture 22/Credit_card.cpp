#include<bits/stdc++.h>
using namespace std;
// const int N = 0;
#define int long long
int n, d;
int a[100005];

void Solve() {
	//By default agar -1 nahi horaha to main bhi nahi karunga:
	int amount = 0;

	for (int i = 0; i < n; i++) {
		if (a[i] == 0) {
			//Is din bank me jaana hain and ye answer mera min nahi
			//hain ye sirf ye karne ke liye hain ki answer exists or not
			if (amount < 0) {
				amount = 0;
			}
		} else {
			amount += a[i];
			if (amount > d) {
				cout << "-1" << endl;
				return;
			}
		}
	}


	//answer will exist:

	amount = 0;
	int visit = 0;
	for (int i = 0; i < n; i++) {
		if (a[i] == 0) {
			if (amount < 0) {
				amount = d;
				visit++;
			}
		} else {
			amount += a[i];
			if (amount > d) {//answer -1 but aisa honahi sakta
				//since my answer exists i will make amound to the
				//max that will not exceed d;
				amount = d;
			}
		}
	}
	cout << visit << endl;
	return;
}




int32_t main() {
	cin >> n >> d;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	Solve();
}
