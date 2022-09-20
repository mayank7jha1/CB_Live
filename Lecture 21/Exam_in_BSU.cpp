#include<bits/stdc++.h>
using namespace std;
// const int N = 0;

int n, m;
int a[200005];
int student[101] = {0};

void Solve() {
	int total = 0;

	for (int i = 0; i < n; i++) {
		int x = total - m + a[i];
		//If this is postive than that means
		//you cannot pass the ith person without failing any.

		int student_removed = 0;
		if (x > 0) {
			for (int j = 100; j >= 1; j--) {
				int y = student[j] * j;

				if (x <= y) {
					student_removed += (x / j);
					/*-ve % m = -ve:
					          (-ve + m) % m = +ve:
					*/
					break;
				}
				student_removed += student[j];
				x = x - y;
			}
		}

		student[a[i]]++;//Iske liye wait karo ye batata hu?
		total += a[i];
		cout << student_removed << " ";
	}

}


int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	Solve();
}