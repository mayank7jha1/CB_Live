#include<bits/stdc++.h>
using namespace std;
// const int N = 0;
#define int long long

int dist[25][25] = {0};//Distance matrix which will store distances.
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
char a[25][25];

int col, row;
int scr_x, scr_y, des_x, des_y;


bool isPossible(int x, int y) {
	return x >= 0 and x<row and y >= 0 and y < col and a[x][y] != 'X';
}

void Dijkstras() {
	dist[scr_x][scr_y] = 0;
	queue<pair<int, int>>q;
	q.push({scr_x, scr_y});


	while (!q.empty()) {
		auto x = q.front();
		q.pop();

		int ci = x.first;
		int cj = x.second;

		for (int i = 0; i < 4; i++) {
			int ni = ci + dx[i];
			int nj = cj + dy[i];

			if (isPossible(ni, nj) and
			        (dist[ni][nj] > (dist[ci][cj] + (a[ci][cj] - '0')))) {
				dist[ni][nj] = dist[ci][cj] + (a[ci][cj] - '0');
				q.push({ni, nj});
			}

		}
	}
}

int32_t main() {
	cin >> col >> row;

	while (col and row) {
		for (int i = 0; i < row; i++) {
			for (int j = 0; j < col; j++) {
				char ch;
				cin >> ch;
				a[i][j] = ch;

				if (ch == 'S') {
					scr_x = i, scr_y = j;
					a[i][j] = '0';
				} else if (ch == 'D') {
					des_x = i, des_y = j;
					a[i][j] = '0';
				}
				dist[i][j] = 1e12;//Initialisation.
			}
		}

		Dijkstras();
		cout << dist[des_x][des_y] << endl;
		cin >> col >> row;
	}
}