#include<bits/stdc++.h>
using namespace std;
// const int N = 0;


bool visited[1001][1001]; bool solution[1001][1001];
//Wherever there is a 1 in the visited array i will not move to that block.
//Wherever there is a 1 in the solution array it means that is the desired solution.

bool RatInMaze(char maze[][1001], int i, int j, int n, int m) {
	//Stoping Condtion:

	if (i == n and j == m) {
		//Make last block in the solution array as 1;
		solution[i][j] = 1;
		for (int x = 0; x <= n; x++) {
			for (int y = 0; y <= m; y++) {
				cout << solution[x][y] << " ";
			}
			cout << endl;
		}
		cout << endl;
		return false;
	}

	//You have reached at a block i,j:

	if (visited[i][j] == 1) {
		return false;
		//Because this can never be a answer as you have already visited the
		//block once and if there was a solution from this block
		//recursion would have already printed it.
	}

	//If you are here that means the block you were standing is not the
	//visited block that is visited[i][j] was 0.

	visited[i][j] = 1;//You are currently visiting this block and moving
	//ahead from here.

	//You have assumed that this block contributes to your answer.

	solution[i][j] = 1;

	//You move foeward from here

	//Option 1: right path:

	if (j + 1 <= m and visited[i][j + 1] == 0) {
		bool small_ans = RatInMaze(maze, i, j + 1, n, m);
		if (small_ans == 1) {
			return true;
		}
	}

	//Option 2: Down Path

	if (i + 1 <= n and visited[i + 1][j] == 0) {
		bool downans = RatInMaze(maze, i + 1, j, n, m);
		if (downans == 1) {
			return true;
		}
	}

	//I had made an assumption while making this i,j as 1 ki we will find a
	//solution from this block now after going right and down i got to know
	//this block can never produce an answer so i will make the solution[i][j]
	//as it was in the original state as 0;

	solution[i][j] = 0;//Backtrack;

	return false;

}


int main() {


	int n, m;
	cin >> n >> m;
	char maze[1001][1001];

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> maze[i][j];
			if (maze[i][j] == 'X') {
				visited[i][j] = 1;
			}
		}
	}

	n--, m--;//Because zero based indexing we are using and 1 based is there in the question

	RatInMaze(maze, 0, 0, n, m);
	// if (ans == false) {
	// 	cout << -1 << endl;
	// }



}