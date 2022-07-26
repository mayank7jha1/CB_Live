#include<bits/stdc++.h>
using namespace std;
// const int N = 0;

int count1[2][2] = {0};

void CountGoodSubstrings(string s) {
	int n = s.length();
	int odd = 0, even = 0;
	for (int i = 0; i < n; i++) {
		odd++;

		if (i % 2 == 1) {
			/*
				This means by rule you are on the odd
				index of the string but since we are
				taking one based indexing in counting our
				length for the palindrome this becomes
				even index.
				Example: 3 index in zero base will become
				4 index in the 1 based indexing.
				So this means you are entering an element\
				in an even place.

			*/
			odd = odd + count1[s[i] - 'a'][0];
			count1[s[i] - 'a'][0]++;
			even = even + count1[s[i] - 'a'][1];
		} else {
			odd += count1[s[i] - 'a'][1];
			count1[s[i] - 'a'][1]++;
			even += count1[s[i] - 'a'][0];
		}
	}
	cout << even << " " << odd << endl;
}

int main() {
	string s;
	cin >> s;

	CountGoodSubstrings(s);
}
