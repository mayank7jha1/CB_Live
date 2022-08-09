#include<bits/stdc++.h>
using namespace std;
// const int N = 0;

int solve(int x, int p) {

//Base Condition:
	if (p == 0) {
		return 1;
	}


	// task=x*x;
	//x*x*x*x*x

//Recursive Call:

	return x * solve(x, p - 1);

}


int main() {
	int x, int p;


	cin >> x >> p;


	//x^p;

	cout << solve(x, p);
}