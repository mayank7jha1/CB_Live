#include<bits/stdc++.h>
using namespace std;
// const int N = 0;



void string_equivalence(char* output, int i, int Max_character, int n) {
	if (i == n) {
		output[i] = '\0';
		cout << output << endl;
		return;
	}



	for (char ch = 'a'; ch <= Max_character; ch++) {

		output[i] = ch;
		//Agar hum maximum element ko us block par fill kar rahe
		//next case ke liye max_character will increment by 1;

		if (ch == Max_character) {
			string_equivalence(output, i + 1, Max_character + 1, n);
		} else {
			string_equivalence(output, i + 1, Max_character, n);
		}
	}
}


int main() {
	int N;
	cin >> N;
	char output[1000];

	string_equivalence(output, 0, 'a', N);
}

// _ _ _ _ _   N=5;

// i=0; 0-4==5 brackets that means wheni==5 that means you are one step ahead.