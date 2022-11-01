// Created by Mayank

#include <bits/stdc++.h>
using namespace std;
#define int long long
class DSU {
	int *parent;
	int *rank;
public:
	DSU(int n) {
		parent = new int[n];
		rank = new int[n];
		for (int i = 0; i < n; i++) {
			parent[i] = -1;
			rank[i] = 1;
		}
	}

	int find_set(int x) {
		if (parent[x] == -1) {
			return x;
		}
		return parent[x] = find_set(parent[x]);
	}
	void union_set(int x, int y) {
		int s1 = find_set(x);
		int s2 = find_set(y);
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
};

class Graph {
	vector<vector<int>>edgelist;
	int V;
public:
	Graph(int V) {
		this->V = V;
	}
	void addEdge(int x, int y, int w) {
		edgelist.push_back({w, x, y});
	}
	int kruskal_mst() {
		DSU s(V);
		sort(edgelist.begin(), edgelist.end());
		int ans = 0;
		for (auto edge : edgelist) {
			int w = edge[0];
			int x = edge[1];
			int y = edge[2];
			if (s.find_set(x) != s.find_set(y)) {
				s.union_set(x, y);
				ans += w;
			}
		}
		return ans;
	}
};


int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	//Graph g(5);
	int n, m;
	cin >> n >> m;
	Graph g(n);
	for (int i = 0; i < m; i++) {
		int x, y, w;
		cin >> x >> y >> w;
		g.addEdge(x - 1, y - 1, w);
	}
	cout << g.kruskal_mst() << endl;

	return 0;
}