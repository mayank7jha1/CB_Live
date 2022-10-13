#include<bits/stdc++.h>
using namespace std;
const int N = 100005;

vector<int>gr[N];

void bfs(int scr, int n, int &ans) {
	vector<int>dis(n + 1, INT_MAX);
	queue<int>q;
	q.push(scr);
	dis[scr] = 0;
	while (!q.empty()) {
		int x = q.front();
		q.pop();
		for (auto nbr : gr[x]) {
			if (dis[nbr] == INT_MAX) {
				dis[nbr] = dis[x] + 1;
				q.push(nbr);
			} else if (dis[nbr] >= dis[x]) {//Backedge
				ans = min(ans, dis[nbr] + dis[x] + 1);
			}
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
		gr[y].push_back(x);
	}

	int ans = n + 1;

	for (int i = 1; i <= n; i++) {
		bfs(i, n, ans);
	}

	if (ans == n + 1) {
		cout << "No Cycle" << endl;
	} else {
		cout << "Shortest Cycle is of length " << ans << endl;
	}
}