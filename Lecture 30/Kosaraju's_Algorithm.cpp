#include<bits/stdc++.h>
using namespace std;
const int N = 100005;
vector<int>gr[N];
vector<int>rev_gr[N];


void dfs(bool *visited, vector<int>&stack, int node) {
	visited[node] = true;
	for (auto nbr : gr[node]) {
		if (!visited[nbr]) {
			dfs(visited, stack, nbr);
		}
	}
	stack.push_back(node);//Ordering based on finish time;
}


void dfs2(bool *visited, int node) {
	visited[node] = true;
	cout << node << " ";
	for (auto nbr : rev_gr[node]) {
		if (!visited[nbr]) {
			dfs2(visited, nbr);
		}
	}
}

void Solve(int n) {
	bool visited[n] = {0};
	vector<int>stack;

	for (int i = 0; i < n; i++) {
		if (!visited[i]) {
			dfs(visited, stack, i);
		}
	}

	memset(visited, 0, sizeof(visited));
	char component = 'A';

	for (int x = stack.size() - 1; x >= 0; x--) {
		int node = stack[x];
		if (!visited[node]) {
			cout << "Component " << component << " ";
			dfs2(visited, node);
			cout << endl;
			component++;
		}
	}
}

int main() {
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		gr[x].push_back(y);
		rev_gr[y].push_back(x);
	}
	Solve(n);
}