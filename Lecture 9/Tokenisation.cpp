#include<bits/stdc++.h>
using namespace std;
// const int N = 0;

int main() {
	char s[] = "My name is Mayank";
	// character arrays are always ended with a null character
	// string s = "My name is Mayank";

	char *token = strtok(s, " "); //character array is equal to a string
	/*
		cout << token << endl;
		token = strtok(NULL, " ");


		cout << token << endl;
	*/
	cout << token << endl;

	while (token != NULL) {
		token = strtok(NULL, " ");
		cout << token << endl;
	}
	// int a[] = {1, 2, 3, 4, 5};

	// cout << *(a + 1) << endl;
	// cout << a[1] << endl;
	// //[] these are overloaded



	// you will have to convert the character array to string

}