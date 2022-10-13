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

	void bfs(T scr, T destination) {
		// map<T, bool>visited;
		map<T, int>distance;

		for (auto x : l) {
			distance[x.first] = INT_MAX;
		}
		queue<T>q;
		q.push(scr);
		distance[scr] = 0;

		while (!q.empty()) {
			T node = q.front();
			//cout << node << " ";
			q.pop();
			for (auto nbr : l[node]) {
				if (distance[nbr] == INT_MAX) {
					q.push(nbr);
					distance[nbr] = distance[node] + 1;
				}
			}
		}

		// for (auto x : l) {
		// 	cout << x.first << "-->" << distance[x.first] << endl;
		// }

		cout << scr << " to " << destination << "-->" << distance[destination] << endl;
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
	int scr, destination;
	cin >> scr >> destination;
	g.bfs(scr, destination);
}