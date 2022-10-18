#include<bits/stdc++.h>
using namespace std;


template<typename T>
class Graph {
	map<T, list<T>>l;
public:
	void add_edge(T x, T y) {
		l[x].push_back(y);
	}


	bool dfs_helper(T scr, map<T, bool>visited, map<T, bool>stack) {
		visited[scr] = true;
		stack[scr] = true;

		for (auto nbr : l[scr]) {
			if ((!visited[nbr] and dfs_helper(nbr, visited, stack)) or stack[nbr]) {
				return true;
			}
		}
		stack[scr] = false;
		return false;
	}

	//Agar node visited nahi hain  and recursion kaam ho! and aage cycle exist karti hain
	//Agar node stack me hain and first vaala bracket vo false hain tab bhi kaam chalega



	//There exists only one component: //Last example:
	//We are saying there exists multiple components

	bool dfs() {
		map<T, bool>visited, stack;
		for (auto x : l) {
			if (!visited[x.first]) {
				bool cycle_found = dfs_helper(x.first, visited, stack);
				if (cycle_found == 1) {
					return true;
				}
			}
		}
		return false;
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
	cout << g.dfs() << endl;

}