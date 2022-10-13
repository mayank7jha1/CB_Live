#include<bits/stdc++.h>
using namespace std;

//No of nodes and no of edges
template<typename T>

class Graph {
	map <T, list<T>>l;
public:
	void addEdge(T x, T y) {
		l[x].push_back(y);
		l[y].push_back(x);
	}

	void bfs(T scr) {
		map<T, bool>visited;
		for (auto x : l) {
			visited[x.first] = false;
		}
		queue<T>q;
		q.push(scr);
		visited[scr] = true;
		while (!q.empty()) {
			T node = q.front();
			cout << node << " ";
			q.pop();
			for (auto nbr : l[node]) {
				if (!visited[nbr]) {
					q.push(nbr);
					visited[nbr] = true;
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
		int s, t;
		cin >> s >> t;
		g.addEdge(s, t);
	}
	g.bfs(0);
}