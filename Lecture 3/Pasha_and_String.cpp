#include<bits/stdc++.h>
using namespace std;
// const int N = 0;
#define ll long long
#define As 200010



int main() {
	char a[As];
	ll count[As] = {0};
	cin >> a;

	ll len = strlen(a);

	ll m;
	cin >> m;//No of Days

	for (int i = 0; i < m; i++) {
		int x;
		cin >> x;//Jo starting point user deraha hain vo 1 based hain but hume
		//to zero based lena hain so humne x-1 par frequency update kara hain rather than
		//on x because we are using zero based index.
		count[x - 1]++;
	}

	// abcdef
	// 5
	// 1 2 3 1 2

	// count [0] = 2;//This is corresponding to ai being 1 which is occuring 2 times in above test case.;
	// count[1] = 2;//ai being 2
	// count[2] = 1;//ai being 3

	ll sum = 0;

	for (int i = 0; i < len / 2; i++) {
		sum += count[i];

		if (sum % 2 == 1) {
			swap(a[i], a[len - i - 1]);
		}
	}

	cout << a << endl;


}