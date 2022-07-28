#include<bits/stdc++.h>
using namespace std;
// const int N = 0;
#define AS 1005
#define int long long


int IPC_Trainers() {
	int Total_Trainers, days;
	cin >> Total_Trainers >> days;

	int starting_date[AS] = {0}, Lectures[AS] = {0}, Sadness[AS] = {0};
	priority_queue<pair<int, int>>pq;

	// pair ka first hain vo sadness rakh raha hu why because i want my
	// priority_queue to be max heap or sorted according to max in the order
	// of sadness.
	//Priority_queue<pair<Sadness,Index>>pq;

	for (int i = 0; i < Total_Trainers; i++) {
		cin >> starting_date[i] >> Lectures[i] >> Sadness[i];
		pq.push({Sadness[i], i});
	}

	int Lectures_Taken[AS] = {0};
	//This array will tell you about how many lectures the corresding index
	//Teacher has taken and how many are left how? we can calulate this
	//by lectures[i]-lectures_taken[i]-1;

	set<int>s;
	for (int i = 1; i <= days; i++) {
		s.insert(i);
	}

	while (!pq.empty()) {
		auto x = pq.top();//This is a pair which contains first as sadness and second as the index of the teacher.
		pq.pop();


		int Index_of_teacher_we_are_taking = x.second;

		int Starting_Teacher_Date = starting_date[Index_of_teacher_we_are_taking];
		int Ending_Teacher_Date = Starting_Teacher_Date + Lectures[Index_of_teacher_we_are_taking] - 1;

		for (int i = Starting_Teacher_Date; i <= Ending_Teacher_Date; i++) {
			auto f = s.lower_bound(i);//>=

			if (f == s.end()) {
				break;
			} else {
				Lectures_Taken[Index_of_teacher_we_are_taking]++;
				s.erase(f);
			}
		}
	}

	int Total_sadness = 0;
	for (int i = 0; i < Total_Trainers; i++) {
		Total_sadness += (Lectures[i] - Lectures_Taken[i]) * Sadness[i];
	}
	return Total_sadness;
}


int32_t main() {
	int t;
	cin >> t;

	while (t--) {
		cout << IPC_Trainers() << endl;;
	}
}