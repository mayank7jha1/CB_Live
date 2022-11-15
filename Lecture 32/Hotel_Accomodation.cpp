#include<bits/stdc++.h>
using namespace std;
// const int N = 0;
int n;

template<typename T>
class Graph {
	unordered_map<T, list<pair<T, int>>>h;
public:
	void addEdge(T x, T y, int distance) {
		h[x].push_back({y, distance});
		h[y].push_back({x, distance});
	}


	int dfs(T node, unordered_map<T, bool>&visited, int *count, int &ans) {
		visited[node] = true;
		count[node] = 1;


		for (auto children : h[node]) {
			int dx = children.second;
			if (!visited[children.first]) {
				count[node] += dfs(children.first, visited, count, ans);

				int right = count[children.first];
				int left = n - right;

				ans += 2 * min(left, right) * dx;
			}
		}
		return count[node];
	}


	int holiday() {
		unordered_map<T, bool>visited;
		int *count = new int[n];
		for (int i = 0; i < n; i++) {
			count[i] = 0;
		}
		int ans = 0;
		dfs(0, visited, count, ans);
		return ans;
	}

};

int main() {
	int t, counter = 1;
	cin >> t;
	while (t--) {
		Graph<int>g;
		cin >> n;
		for (int i = 1; i < n; i++) {
			int x, y, z;
			cin >> x >> y >> z;
			g.addEdge(x - 1, y - 1, z);
		}
		cout << "Case #" << counter << ": " << g.holiday() << endl;
		counter++;
	}
}



