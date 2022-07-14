#include<bits/stdc++.h>
using namespace std;


int main() {
	int n;
	cin >> n;
	int a[n];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	int left_max[n + 1];
	int right_min[n + 1];

	left_max[0] = INT_MIN;
	for (int i = 1; i <= n; i++) {
		left_max[i] = max(left_max[i - 1], a[i - 1]);
	}


	right_min[n] = INT_MAX;
	for (int i = n - 1; i >= 0; i--) {
		right_min[i] = min(right_min[i + 1], a[i]);
	}


	int partition = 1;
	for (int i = 1; i < n; i++) {
		if (left_max[i] <= right_min[i]) {
			partition++;
		}
	}
	cout << partition << endl;
	//cout << "Mayakn";
}