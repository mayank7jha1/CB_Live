//last edit 16-06-22 17:20
#include<iostream>
//#include<vector>
//#include<cstring>
#include<algorithm>
//#include<climits>
//#include<map>
//#include<unordered_map>
//#include<queue>
//#include<stack>
//#include<list>
//#include<set>
const int N = 100005;
using namespace std;
#define ll long long
#define endl '\n'
#define pii pair<int, int>
#define pll pair<ll, ll>
#define vi vector<int>
#define vll vector<ll>


int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int t = 1;
	//cin>>t;
	while(t--){
		int n, k;
		cin>>n>>k;
		int arr[n];
		for (int i = 0; i < n; ++i){
			cin>>arr[i];
		}

		ll count = 0;
		for (int i = 0; i + 2 < n; ++i){
			auto l = lower_bound(arr, arr+n, arr[i]+k);
			int j = l - arr;//index of the maximum value(arr[j]) which can be a part
			//of triplet including arr[i]

			if(arr[j] != arr[i] + k)
				j--;

			int x = j - i;

			if(x > 1)
				count += (x*(x-1)/2);
		}

		cout<<count;

	}
	return 0;
}