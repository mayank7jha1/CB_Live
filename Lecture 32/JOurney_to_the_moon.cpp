#include<bits/stdc++.h>
using namespace std;
// const int N = 0;
#define int long long

int n, p;

template<typename T>
class Graph {
	unordered_map<T, list<T>>h;
public:
	void addEdge(T x, T y, bool direction = true) {
		h[x].push_back(y);
		if (direction == true) {
			h[y].push_back(x);
		}
	}

	void dfs(T node, unordered_map<T, bool>&visited, int &count) {
		visited[node] = true;//0 ko visit kiya hain.
		count++;

		for (auto children : h[node]) {
			if (!visited[children]) {
				dfs(children, visited, count);
			}
		}
	}

	void journey_to_moon() {
		unordered_map<T, bool>visited;
		int total = (n * (n - 1)) / 2;
		int count = 0;

		dfs(0, visited, count);
		total -= (count * (count - 1)) / 2;

		for (auto node : h) {
			count = 0;
			if (!visited[node.first]) {
				dfs(node.first, visited, count);
				total -= (count * (count - 1)) / 2;
			}
		}
		cout << total << endl;
	}
};

int32_t main() {
	Graph<int>g;

	cin >> n >> p;
	for (int i = 0; i < p; i++) {
		int x, y;
		cin >> x >> y;
		g.addEdge(x, y);
	}

	g.journey_to_moon();
}