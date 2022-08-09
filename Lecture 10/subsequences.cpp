#include<bits/stdc++.h>
using namespace std;
// const int N = 0;

void Solve(char* in, char *output, int i, int j) {
	//i is for iterating over input array
	//j is for iterating over output array



	//Base Case or Stoping Condition
	if (in[i] == '\0') {
		output[j] = '\0';
		cout << output << endl;
		return;
	}

	output[j] = in[i];
	Solve(in, output, i + 1, j + 1);

	//Recursion Task:
	//When you don't take the element:
	Solve(in, output, i + 1, j);

	//When you take the element:


}

int main() {
	char in[10000];//Since ye character array hain: that means it will
	//end on NULL Character:
	cin >> in;

	char output[10000];

	Solve(in, output, 0, 0);
}


// input: a b c \0    i = 2;
// output: b c \0    j = 1;