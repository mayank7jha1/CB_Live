#include<bits/stdc++.h>
using namespace std;
// const int N = 0;

int main() {
	int t;
	cin >> t;
	while (t--) {
		string keyboard, word;
		cin >> keyboard >> word;

		int mapping[256] = {0};

		for (int i = 0; i < 26; i++) {
			mapping[keyboard[i]] = i + 1;
		}


		int ans = 0;

		for (int i = 0; i < word.length() - 1; i++) {
			ans += abs(mapping[word[i + 1]] - mapping[word[i]]);
		}

		cout << ans << endl;
	}
}