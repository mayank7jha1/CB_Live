#include<bits/stdc++.h>
using namespace std;
// const int N = 0;

int n, h, l, r;
int a[100005];

int Sleeping_Schedule(int i, int waking_hour) {
	//Base Case:

	if (i == n) {
		//That means you have already calculated your ans.
		return 0;
	}

	int option1_Waking_hour = (waking_hour + a[i]) % h;
	int option2_Waking_Hour = (waking_hour + (a[i] - 1)) % h;

	int ans1 = 0, ans2 = 0;

	if (option1_Waking_hour >= l and option1_Waking_hour <= r) {
		ans1 = 1;
	}
	if (option2_Waking_Hour >= l and option2_Waking_Hour <= r) {
		ans2 = 1;
	}

	int op1 = Sleeping_Schedule(i + 1, option1_Waking_hour) + ans1;
	int op2 = Sleeping_Schedule(i + 1, option2_Waking_Hour) + ans2;

	return max(op1, op2);
}

int main() {
	cin >> n >> h >> l >> r;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	/*	at which sleep you are currently at:
		because we want recursion to go forward and when
		your sleep has reached the as n that is the total no of
		sleep you say stop:*/

	/*
	YOu also need the walking time because without the waking
	time how are you you suppose to calculate the starting time
	of the next sleep;

	t=0: 15 hour and 16 hour
	15: wake 7 hour from here
	*/
	cout << Sleeping_Schedule(0, 0);
}