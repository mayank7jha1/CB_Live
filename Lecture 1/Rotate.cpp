#include<bits/stdc++.h>
using namespace std;
// const int N = 0;


int main() {
	int n;
	cin >> n;
	int a[n];

	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	//Left rotation 2 times
	// rotate(a, a + 2, a + n);

	// for (int i = 0; i < n; i++) {
	// 	cout << a[i] << " ";
	// }

	//Right rotation 2 times that means basically
	//rotate the array n-2 times towards left.
	/*rotate(a, a + (n - 2), a + n);
	//cout << endl;

	for (int x : a) {
		cout << x << " ";
	}
	*/

	//Step 1 reverse the array:
	//reverse(a, a + n);

	int i = 0;
	int j = n - 1;

	while (i <= j) {
		swap(a[i], a[j]);
		i++;
		j--;
	}


	//2 Step : reverse first k element
	//since it is an array so indexin 0 based
	//0---k-1;
	reverse(a, a + 2);


	//stl ke functions:
	//address of the initial elements are always included
	//address of the last element are excluded.


	//Step 3:

	reverse(a + 2, a + n);

	for (int x : a) {
		cout << x << " ";
	}


	// 1 2 3 4 5
	// //6 TIMES ROTATE KARNA HAIN:
	// 2 3 4 5 1
	// 3 4 5 1 2
	// 4 5 1 2 3
	// 5 1 2 3 4
	// 1 2 3 4 5

	// 2 3 4 5 1

	// k = k % n;





}