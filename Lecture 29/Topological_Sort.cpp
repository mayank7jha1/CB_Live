#include<bits/stdc++.h>
using namespace std;


template<typename T>
class Graph {
	map<T, list<T>>l;
public:
	void add_edge(T x, T y) {
		l[x].push_back(y);
	}

	void dfs_helper(T scr, map<T, bool>&visited, list<T>&ordering) {
		visited[scr] = true;
		for (auto nbr : l[scr]) {
			if (!visited[nbr]) {
				dfs_helper(nbr, visited, ordering);
			}
		}
		ordering.push_front(scr);
		return;
	}

	void dfs() {
		map<T, bool>visited;
		list<T>ordering;
		for (auto x : l) {
			visited[x.first] = false;
		}

		for (auto x : l) {
			T node = x.first;
			if (!visited[node]) {
				dfs_helper(node, visited, ordering);
			}
		}

		for (auto x : ordering) {
			cout << x << " ";
		}
	}

	void topological_sort_bfs(int n) {
		map<T, int>indegree;
		for (auto x : l) {
			indegree[x.first] = 0;
		}

		//Resolving the indegree of the graph:

		for (auto x : l) {
			for (auto p : x.second) {
				indegree[p]++;
			}
		}

		//Actual BFS:
		queue<T>q;
		for (auto x : indegree) {
			if (x.second == 0) {
				q.push(x.first);
			}
		}

		while (!q.empty()) {
			T node = q.front();
			cout << node << " ";
			q.pop();
			for (auto nbr : l[node]) {
				indegree[nbr]--;
				if (indegree[nbr] == 0) {
					q.push(nbr);
				}
			}
		}
	}
};

int main() {
	Graph<int>g;
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		g.add_edge(x, y);
	}
	g.dfs();
	cout << endl;
	g.topological_sort_bfs(n);

}