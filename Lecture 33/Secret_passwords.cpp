#include<bits/stdc++.h>
using namespace std;
// const int N = 0;
#define int long long

class dsu {
	vector<int>parent, rank;
	int totalcomponents;
public:
	dsu(int n) {
		parent.resize(n);
		rank.resize(n);
		for (int i = 0; i < n; i++) {
			parent[i] = i;
			rank[i] = 0;
			totalcomponents = n;
		}
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


int n;
string s[200005];

int32_t main() {
	dsu g(26);
	cin >> n;
	for (int i = 0; i < n; i++) {
		string s1;
		cin >> s1;
		s[i] = s1;

		for (int j = 0; j < s1.length() - 1; j++) {
			g.union_set(s1[j] - 'a', s1[j + 1] - 'a');
		}
	}

	int c[26] = {0};//THis is for elements of can be considered
	//individual superparents;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < s[i].length(); j++) {
			c[g.find_set(s[i][j] - 'a')]++;
		}
	}
	// 2*(10^5)*50
	int ans = 0;
	for (int i = 0; i < 26; i++) {
		if (c[i]) {
			ans++;
		}
	}

	cout << ans << endl;
}


