#include<bits/stdc++.h>
using namespace std;
// const int N = 0;


class dsu {
	vector<int>parent, rank;
	int totalcomponents;
public:
	dsu(int n) {
		parent.resize(n);
		rank.resize(n);
		for (int i = 0; i < n; i++) {
			parent[i] = i, rank[i] = 0;
		}
		totalcomponents = n;
	}

	int find_set(int a) {
		if (a == parent[a]) {
			return a;
		}
		return parent[a] = find_set(parent[a]);
	}

	void union_set(int a, int b) {
		a = find_set(a);
		b = find_set(b);

		if (a != b) {
			if (rank[a] < rank[b]) {
				swap(a, b);
			}
			parent[b] = a;
			if (rank[a] == rank[b]) {
				rank[a]++;
			}
			totalcomponents--;
		}
	}
};


int c[200005][26];
int main() {
	int t;
	cin >> t;
	int n, k;
	string s;

	while (t--) {
		cin >> n >> k >> s;
		dsu g(n);
		//Joining According to condition 1:
		for (int i = 0; i < n; i++) {
			g.union_set(i, n - i - 1);
		}
		//according to condition 2:
		for (int i = 0; i < n - k; i++) {
			g.union_set(i, i + k);
		}

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < 26; j++) {
				c[i][j] = 0;
			}
		}

		for (int i = 0; i < n; i++) {
			c[g.find_set(i)][s[i] - 'a']++;
		}

		int ans = 0;
		for (int i = 0; i < n; i++) {
			if (g.find_set(i) == i) {
				int sum = 0;
				int max_occuring_character = 0;
				//row represent ek component
				for (int j = 0; j < 26; j++) {
					sum += c[i][j];
					max_occuring_character = max(max_occuring_character, c[i][j]);
				}
				ans += sum - max_occuring_character;
			}
		}
		cout << ans << endl;
	}
}