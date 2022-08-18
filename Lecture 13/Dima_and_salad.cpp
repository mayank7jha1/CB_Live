#include<bits/stdc++.h>
using namespace std;
// const int N = 0;
#define int long long
int n, k;
int *taste, *calorie;

int Dima_and_Salad(int i, int sum) {
	if (i == n) {
		//i==n that means i have exhausted all the fruits from 0 - n-1.
		//that means i have either chosen a fruit or not chosen a fruit and reached here.

		//that means i have already calculated the taste of all the fruits
		//which i already picked while reaching upto n.

		if (sum == 0) {
			return 0;
		}

		//Lets say i have reached n and the sum is not zero in this scenario
		//i have to make sure that i donot ever choose this option.
		//return something that can never be your answer.
		//since i am taking maximum out of the two options so since
		//option cannot be the answer what i will do is i will return the
		//smallest value possible.

		return -1e12;
	}

	int option1 = taste[i] + Dima_and_Salad(i + 1, sum + taste[i] - k * calorie[i]);

	int option2 = 0 + Dima_and_Salad(i + 1, sum);

	return max(option1, option2);
}


int32_t main() {
	cin >> n >> k;
	taste = new int[n];
	calorie = new int[n];
	for (int i = 0; i < n; i++) {
		cin >> taste[i];
	}
	for (int i = 0; i < n; i++) {
		cin >> calorie[i];
	}
	//Two Parameters are there:
	//1. iterator to move forward
	//2. Total Sum up uptil now

	int ans = Dima_and_Salad(0, 0);
	if (ans <= 0) {
		cout << "-1" << endl;
	} else {
		cout << ans << endl;
	}
}