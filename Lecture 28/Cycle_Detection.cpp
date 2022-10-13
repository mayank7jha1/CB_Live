#include<bits/stdc++.h>
using namespace std;
template<typename T>

class Graph {
	map <T, list<T>>l;
public:
	void addEdge(T x, T y) {
		l[x].push_back(y);
		l[y].push_back(x);
	}

	bool dfs_helper(T scr, map<T, bool>&visited, T parent) {
		visited[scr] = true;

		for (auto x : l[scr]) {
			if (!visited[x]) {
				bool cycle = dfs_helper(x, visited, scr);
				if (cycle) {
					return true;
				}
			} else if (x != parent) {
				return true;
			}
		}
		return false;
	}

	bool dfs(T scr) {
		map<T, bool>visited;

		for (auto x : l) {
			visited[x.first] = false;
		}

		return dfs_helper(1, visited, -1);
	}
};



int main() {
	Graph<int>g;
	int n, m;
	cin >> n >> m;


	for (int i = 0; i < m; i++) {
		int s, t;
		cin >> s >> t;
		g.addEdge(s, t);
	}
	g.dfs(0);
}