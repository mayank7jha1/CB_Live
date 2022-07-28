#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 0;



int Travel_cards() {
	int n, a, b, k, f;
	cin >> n >> a >> b >> k >> f;

	map<pair<string, string>, int>m;//C++ this cannot be unordered.

	string prev_dest = "";

	for (int i = 0; i < n; i++) {

		string start_dest, ending_dest;
		cin >> start_dest >> ending_dest;
		int price;

		if (prev_dest == start_dest) {
			//This is a Tranashipment
			price = b;
		} else {
			price = a;
		}
		prev_dest = ending_dest;

		if (start_dest > ending_dest) {
			swap(start_dest, ending_dest);
			//Taaki map ke ander i don't have different keys
			//for the same type of trip and i can calcalute the
			//entire same type trip cost at one place only.
		}

		if (m.find({start_dest, ending_dest}) != m.end()) {
			//Update the cost
			m[make_pair(start_dest, ending_dest)] += price;
		} else {
			//This key or trip was not in the map hence add it
			m[make_pair(start_dest, ending_dest)] = price;
		}
	}

	vector<int>v;
	int total_cost = 0;

	for (auto x : m) {
		v.push_back(x.second);
		total_cost += x.second;
	}

	sort(v.rbegin(), v.rend());

	// sort(v.begin, v.end(), greater<int>());

	for (int i = 0; i < k; i++) {
		if (v[i] >= f) {
			total_cost = total_cost - v[i] + f;
		} else {
			break;
		}
	}

	return total_cost;

}


int32_t main() {
	cout << Travel_cards() << endl;
}




