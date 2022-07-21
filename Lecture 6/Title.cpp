#include<bits/stdc++.h>
using namespace std;
// const int N = 0;
bool freq[30] = {0};

void Title(char *a, int k) {
	int i = 0;
	int j = strlen(a) - 1;
	while (i < j) {
		if (a[i] == '?' and a[j] == '?') {

			i++; j--;
			continue;

		} else if (a[i] != '?' and a[j] == '?') {
			a[j] = a[i];
			freq[a[i] - 'a' + 1] = true;
			i++, j--;
		} else if (a[i] == '?' and a[j] != '?') {
			a[i] = a[j];
			freq[a[i] - 'a' + 1] = true;

			i++, j--;
		}  else if (a[i] == a[j]) {
			freq[a[i] - 'a' + 1] = true;

			i++, j--;
		} else {
			cout << "IMPOSSIBLE" << endl;
			return;
		}
	}

	if (i == j and a[i] != '?') {
		freq[a[i] - 'a' + 1] = true;
	}

	//i==j; now we will move from inner to outwards why?
	//because we want to place the greatest character in the innermost
	// question but only after checking the value of k.

	/*	a b ? ?? d ?? ? b a;   k = 4;

		freq[a] = true;
		freq[d] = true;

		freq[b] = false;
		freq[c] = false;
		k = 4;
		freq[4] = true ya false;
		freq[3] = false;

		i == j; that means the inner most bracket;*/

	while (i >= 0) {
		while (k > 1 and freq[k] == true) {
			k--;
		}

		if (a[i] == '?' and a[j] == '?') {
			a[i] = a[j] = 'a' + k - 1;
			freq[k] = true;
			j++,
			i--;
		} else {
			i--;
			j++;
		}
	}

	if (k == 1 and freq[k] == true) {
		cout << a << endl;
	} else {
		cout << "IMPOSSIBLE" << endl;
	}
}

int main() {
	int k;
	cin >> k;
	char a[2001];
	cin >> a;
	//cout << a << endl;
	Title(a, k);
	//cout << "Mayank";
}