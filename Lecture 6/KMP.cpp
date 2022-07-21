#include<bits/stdc++.h>
using namespace std;
int table[100005] = {0};

void CalculateTable(string p) {
	int i = 1;
	int j = 0;
	int lp = p.length();
	while (i < lp) {

		while (j > 0 and p[i] != p[j]) {
			j = table[j - 1];
		}

		if (p[i] == p[j]) {
			table[i] = j + 1;
			i++;
			j++;
		} else {
			i++;
		}
	}
}


void KMP(string s, string p) {
	CalculateTable(p);

	int i = 0;//This is for iterating over string.
	int j = 0;//This is for iterating over pattern.
	int ls = s.length();
	int lp = p.length();

	while (i < ls) {

		while (j > 0 and s[i] != p[j]) {
			j = table[j - 1];
		}

		if (s[i] == p[j]) {
			i++;
			j++;
		} else {
			//For the first character only you cannot go prior to this.
			//for s[i]!=p[j] and j==0 you cannot go to the negative index.
			i++;
		}
		if (j == lp) {
			cout << i - j << endl;
			//Starting point of the pattern in the string.
			j = table[j - 1];
		}
	}
	cout << endl;
}




int main() {
	int n;
	while (cin >> n) {
		string s, p;
		cin >> p >> s;
		KMP(s, p);
	}

}