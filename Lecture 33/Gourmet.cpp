#include<bits/stdc++.h>
using namespace std;
// const int N = 0;
#define int long long

class dsu {
	vector<int>parent, rank;
	int totalcomponents;
public:
	dsu(int n) {
		parent.resize(n);
		rank.resize(n);
		for (int i = 0; i < n; i++) {
			parent[i] = i;
			rank[i] = 0;
			totalcomponents = n;
		}
	}
	int find_set(int a) {
		if (a == parent[a]) {
			return a;
		}
		return parent[a] = find_set(parent[a]);
	}

	void union_set(int a, int b) {
		a = find_set(a);
		b = find_set(b);

		if (a != b) {
			if (rank[a] < rank[b]) {
				swap(a, b);
			}
			parent[b] = a;
			if (rank[a] == rank[b]) {
				rank[a]++;
			}
			totalcomponents--;
		}
	}
};


vector<pair<int, int>>edgelist;
vector<int>adlist[3001];
bool visited[30001];
int depth[3001] = {0};
bool KyaCyclePresentHai = false;
bool kyaNodeAldreadyPresentHai[3001] = {0};

void FindDepth(int node) {
	if (visited[node]) {
		return;
	}

	//Tumko ye kaise pata chalega ki cycle hain ki nahi:

	//If in a dfs if we visit a node which is not the parent
	//we say there exists a cycle;//Directed graph:

	if (KyaCyclePresentHai == true) {
		return;
	}

	if (kyaNodeAldreadyPresentHai[node] == true) {
		KyaCyclePresentHai = true;
		return;
	}

	kyaNodeAldreadyPresentHai[node] = true;///THis can be considered as instack of the cycle detection thing we did in directed graph

	int d = 0;
	for (auto children : adlist[node]) {
		FindDepth(children);
		d = max(d, depth[children]);
	}
	depth[node] = d + 1;
	kyaNodeAldreadyPresentHai[node] = false;
	//false isliye karna hain aisa hosakta hain ki main kisi
	//aur raste se is par aajau.
	visited[node] = true;
}

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;
	cin >> n >> m;
	dsu g(n + m);//Because i am considering the j as seperate nodes

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			char ch;
			cin >> ch;
			if (ch == '=') {
				g.union_set(i, n + j);
			} else if (ch == '>') {
				edgelist.push_back({i, n + j});
			} else {
				edgelist.push_back({n + j, i});
			}
		}
	}

	for (auto x : edgelist) {
		adlist[g.find_set(x.first)].
		push_back(g.find_set(x.second));
	}

	for (int i = 0; i < n + m; i++) {
		if (!visited[g.find_set(i)]) {
			FindDepth(g.find_set(i));
		}
	}

	if (KyaCyclePresentHai == 1) {
		cout << "No" << endl;
	} else {
		cout << "Yes" << endl;
		for (int i = 0; i < n; i++) {
			cout << depth[g.find_set(i)] << " ";
		}
		cout << endl;
		for (int j = 0; j < m; j++) {
			cout << depth[g.find_set(n + j)] << " ";
		}
		cout << endl;
	}
}


/*
Edgelist::   dsu   0 1 2 3 4 5

0----->5, 3, 4
2----->3, 4, 5
3----->1
4----->1
5----->1

DFS: Depth find karlo and store karlo kahi:
*/