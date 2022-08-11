#include<bits/stdc++.h>
using namespace std;
// const int N = 0;

int n;
int grid[10][10] = {0};
int Total_Places_Knight_can_Move;
int ans = -1;
int N = 10;

int dx[] = {1, 1, 2, 2, -1, -1, -2, -2};
int dy[] = {2, -2, 1, -1, 2, -2, 1, -1};


//single coordinate== (dx[i],dy[i])

void input_grid() {
	for (int i = 0; i < n; i++ ) {
		for (int j = 0; j < n; j++) {
			cin >> grid[i][j];
			if (grid[i][j] == 1) {
				Total_Places_Knight_can_Move++;
			}
		}
	}
}

void Knight(int x, int y, int count) {

	ans = max(count, ans);

	for (int i = 0; i < 8; i++) {
		int x_coordinate = x + dx[i];
		int y_coordinate = y + dy[i];

		if (x_coordinate >= 0 and x_coordinate<N and y_coordinate >= 0
		        and y_coordinate < N and grid[x_coordinate][y_coordinate] == 1) {

			grid[x_coordinate][y_coordinate] = 0;
			//That means in this path you cannot visit this block;

			Knight(x_coordinate, y_coordinate, count + 1);

			grid[x_coordinate][y_coordinate] = 1;//Backtrack
		}
	}

}


//If you are at x,y coordinate then you have 8 options to move:

//





int main() {
	cin >> n;
	input_grid();
	//Count=In a Single Path the no of Boxes you were
	//able to visit;

	//Since you are standing at 0,0 so you can always
	//include 0,0;

	grid[0][0] = 0;//Why because we have initialised
	//count as 1 in that way we are already including
	//0,0 co-ordinates all the time.

	Knight(0, 0, 1);

	//Variable ans= Stores the maximum no of boxes you
	// were able to visit in a single path.
	//cout << n << Total_Places_Knight_can_Move << endl;
	//cout << "Mayank" << endl;
	cout << Total_Places_Knight_can_Move - ans << endl;
}