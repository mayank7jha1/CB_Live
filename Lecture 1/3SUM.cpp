#include<bits/stdc++.h>
using namespace std;
#define ll long long
int cnt[10];

int main() {
	int t;
	cin >> t;
	while (t--) {
		ll n;
		cin >> n;
		for (int i = 0; i < 10; i++) {
			cnt[i] = 0;
		}
		for (int i = 1; i <= n; i++) {
			int x;
			cin >> x;
			x = x % 10;
			cnt[x]++;
		}

		vector<int>v;
		for (int i = 0; i <= 9; i++) {
			for (int j = 0; j < min(cnt[i], 3); j++) {
				v.push_back(i);
			}
		}

		int flag = 0;
		int len = v.size();
		for (int i = 0; i < len; i++) {
			for (int j = i + 1; j < len; j++) {
				for (int k = j + 1; k < len; k++) {
					if ((v[i] + v[j] + v[k]) % 10 == 3) {
						flag = 1;
						break;
					}
				}
			}
		}

		if (flag == 1) {
			cout << "Yes" << endl;
		} else {
			cout << "No" << endl;
		}
	}
}