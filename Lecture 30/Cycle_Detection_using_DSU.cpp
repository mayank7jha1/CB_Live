// Created by Mayank

#include <bits/stdc++.h>
using namespace std;

class Graph {
	list<pair<int, int>>l;
public:
	void addEdge(int x, int y) {
		l.push_back({x, y});
	}

	int find_set(int x, int *parent) {
		if (parent[x] == -1) {
			return x;
		}
		return parent[x] = find_set(parent[x], parent);
	}
	void union_set(int x, int y, int *parent, int *rank) { //O(1)
		int s1 = find_set(x, parent);
		int s2 = find_set(y, parent);
		if (s1 != s2) {
			if (rank[s1] < rank[s2]) {
				parent[s1] = s2;
				rank[s2] += rank[s1];
			} else {
				parent[s2] = s1;
				rank[s1] += rank[s2];
			}

		}
	}
	bool cycle(int n) {
		int *parent = new int[n];
		int *rank = new int[n];
		for (int i = 0; i < n; i++) {
			parent[i] = -1;
			rank[i] = 1;
		}
		for (auto egde : l) {
			int x = egde.first;
			int y = egde.second;
			int s1 = find_set(x, parent);
			int s2 = find_set(y, parent);
			if (s1 != s2) {
				union_set(s1, s2, parent, rank);
			} else {
				return true;
			}
		}
		return false;
	}
};

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	Graph g;
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		g.addEdge(x, y);
	}
	cout << g.cycle(n) << endl;
	return 0;
}