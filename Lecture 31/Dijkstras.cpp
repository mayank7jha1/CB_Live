#include<bits/stdc++.h>
using namespace std;
#define int long long
template<typename T>

class Graph {
	unordered_map < T, list<pair<T, int>>>l;
public:
	void addEdge(T x, T y, int w) {
		l[x].push_back({y, w});
		l[y].push_back({x, w});
	}

	void Dijkstras(T scr) {
		unordered_map<T, int>distance;
		set < pair<int, int>>s;
		for (auto x : l) {
			distance[x.first] = INT_MAX;
		}
		distance[scr] = 0;
		s.insert({0, scr});//weight,node
		while (!s.empty()) {
			auto p = *(s.begin());
			s.erase(s.begin());
			T node = p.second;
			T parent_weight = p.first;

			for (auto children : l[node]) {
				int edge_weight = children.second;

				if (distance[children.first] > parent_weight + edge_weight) {
					auto f = s.find({distance[children.first], children.first});
					if (f != s.end()) {
						s.erase(f);
					}

					distance[children.first] = parent_weight + edge_weight;
					s.insert({distance[children.first], children.first});
				}
			}
		}
		for (auto node : l) {
			cout << "Distance of " << node.first << " from scr " << scr << " is " <<
			     distance[node.first] << endl;
		}
	}
};

int32_t main() {
	int n, m;
	cin >> n >> m;
	Graph<int>g;
	for (int i = 0; i < m; i++) {
		int x, y, w;
		cin >> x >> y >> w;
		g.addEdge(x, y, w);
	}
	int scr;
	cin >> scr;
	g.Dijkstras(scr);
}