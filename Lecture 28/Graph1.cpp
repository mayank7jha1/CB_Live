#include<bits/stdc++.h>
using namespace std;

//No of nodes and no of edges
template<typename T>

class Graph {
	map <T, list<T>>l;
public:
	void addEdge(T x, T y, bool bidirectional) {
		l[x].push_back(y);
		if (bidirectional == 1) {
			l[y].push_back(x);
		}
	}

	void printlist() {
		for (auto x : l) {
			T s = x.first;
			cout << s << " -->" << " ";
			list<T> nbr = x.second;
			for (auto t : nbr) {
				cout << t << " ";
			}
			cout << endl;
		}
		cout << endl;
	}

};



int main() {
	Graph<string>g;
	int n, m;
	cin >> n >> m;


	for (int i = 0; i < m; i++) {
		string s, t;
		cin >> s >> t;
		g.addEdge(s, t, 1);
	}
	g.printlist();
}