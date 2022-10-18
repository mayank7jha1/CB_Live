#include<bits/stdc++.h>
using namespace std;
const int N = 100005;
vector<int>gr[N];



bool dfs_helper(int node, int parent, int* visited, int color) {

	visited[node] = color;

	for (auto nbr : gr[node]) {
		if (visited[nbr] == 0) {
			int small_ans = dfs_helper(nbr, node, visited, 3 - color);
			if (small_ans == 0) {
				return false;
			}
		} else if (nbr != parent and visited[nbr] == color) {
			return false;
		}
	}
	return true;
}

//Graph contains only one component;

bool dfs(int n) {
	int visited[n] = {0};//visited: 0 for not visited element
	//1 for visited and colored as 1
	//2 for visited and colored as 2.
	int color = 1;

	int ans = dfs_helper(0, -1, visited, color);
	//har ek unvisited node par lagana hain:

	for (int i = 0; i < n; i++) {
		cout << i << " - Color - " << visited[i] << endl;
	}
	return ans;
}


int main() {
	int n, m;
	cin >> n >> m;

	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		gr[x].push_back(y);
		gr[y].push_back(x);
	}

	if (dfs(n) == 1) {
		cout << "Yes" << endl;
	} else {
		cout << "No" << endl;
	}
}