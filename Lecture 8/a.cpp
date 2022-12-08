#include<bits/stdc++.h>
using namespace std;
// const int N = 0;
#define int long long

int Travel_Cards() {
	int n, a, b, k, f;
	cin >> n >> a >> b >> k >> f;

	map<pair<string, string>, int>m;//JOurney(ek pair hain) and cost

	string prev_dest = "";
	for (int i = 0; i < n; i++) {
		string start_point, ending_point;
		cin >> start_point >> ending_point;
		int price;

		if (prev_dest == start_point) {
			//THis is a transhipment:
			price = b;
		} else {
			price = a;
		}
		prev_dest = ending_point;

		if (start_point > ending_point) {
			swap(start_point, ending_point);
		}

		if (m.find({start_point, ending_point}) != m.end()) {
			m[ {start_point, ending_point}] += price;
		} else {
			m[ {start_point, ending_point}] = price;
		}
	}


	vector<int>v;
	int total_cost = 0;

	for (auto x : m) {
		v.push_back(x.second);
		total_cost += x.second;
	}
	//cout << total_cost << endl;

	sort(v.rbegin(), v.rend());
	// for (auto x : v) {
	// 	cout << x << endl;
	// }
	// cout << k << endl;
	for (int i = 0; i < k and i < v.size(); i++) {
		if (v[i] >= f) {
			//cout << v[i] << " " << total_cost << " ";

			total_cost = total_cost - v[i] + f;
		} else {
			break;
		}
	}
	// cout << endl;
	// cout << total_cost << endl;
	return total_cost;
}



int32_t main() {
	cout << Travel_Cards() << endl;
}
