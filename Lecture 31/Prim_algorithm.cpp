#include<bits/stdc++.h>
using namespace std;
// const int N = 0;

//#define int long long


class Graph {
//Adj. list
	vector<pair<int, int>>*l;
	int V;

public:
	Graph(int n) {
		V = n;
		l = new vector<pair<int, int>>[n];
	}

	void addEdge(int x, int y, int w) {
		l[x].push_back({y, w});
		l[y].push_back({x, w});
	}

	int prim_mst() {
		// should give us egge according to weight
		priority_queue < pair <int, int>, vector<pair<int, int>>, greater<pair<int, int>>>q;

		bool* visited = new bool[V] {0};
		q.push({0, 0});//Weight,node
		int ans = 0;
		while (!q.empty()) {
			auto x = q.top();
			q.pop();
			int to_edge = x.second;
			int weight = x.first;

			if (visited[to_edge] == 1) {
				continue;
			}
			ans += weight;
			visited[to_edge] = 1;
			for (auto nbr : l[to_edge]) {
				if (visited[nbr.first] == 0) {
					q.push({nbr.second, nbr.first});
				}
			}
		}
		return ans;
	}
};
int32_t main() {
	int n, m;
	cin >> n >> m;
	Graph g(n);
	for (int i = 0; i < m; i++) {
		int x, y, w;
		cin >> x >> y >> w;
		g.addEdge(x - 1, y - 1, w);
	}
	cout << g.prim_mst() << endl;
}