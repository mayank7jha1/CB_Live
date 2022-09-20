#include<bits/stdc++.h>
using namespace std;
#define int long long


class Activity {
public:
	int starting_time;
	int ending_time;
};

Activity a[100005];//Ek object ka array banaya hain:

bool compare(Activity a, Activity b) {
	/*if (a.ending_time < b.ending_time) {
		return true;
	} else {
		return false;
	}*/

	if (a.ending_time == b.ending_time) {
		return a.starting_time < b.starting_time;
	}

	return a.ending_time < b.ending_time;//Sort hoga acc. order me
	//according to ending time.
}


void Solve(int n) {
	sort(a, a + n, compare);

	int ans = 1;
	int prev_ending_time = a[0].ending_time;

	for (int i = 0; i < n; i++) {
		if (a[i].starting_time >= prev_ending_time) {
			ans++;
			prev_ending_time = a[i].ending_time;
		}
	}
	cout << ans << endl;
}

int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;

		for (int i = 0; i < n; i++) {
			cin >> a[i].starting_time >> a[i].ending_time;
		}
		Solve(n);
	}
}



// c++ is the fastest language: // java://python
//c language vo fast:
//oops and stl:

//stack:

//C faster:

//spoj ke questions and codeforces:

//CP 3000 :  printf and scanf instead of cin or cout:

//apprach sahi hogi but tle: input output slow:
//scanf and printf:

//technique: sync: stdio ko iostream ke sath sync kardo:

//cin and cout iostream and isse ye hoga ki jab tun cin scanf
// cout ---printf

//buffer reader: