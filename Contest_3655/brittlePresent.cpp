//last edit 16-06-22 17:20
#include<iostream>
//#include<vector>
#include<cstring>
//#include<algorithm>
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
		string s;
		cin>>s;
		int n = s.length(), l = 0, r = n - 1;
		
		bool removed[n] = {0};

		int countOfRemovals = 0;
		while(l < r){
			while(l < r and s[l] != '(')
				l++;
			while(l < r and s[r] != ')')
				r--;
			if(l < r and s[l] == '(' and s[r] == ')'){
				removed[l] = true;
				removed[r] = true;
				l++;
				r--;
				countOfRemovals += 2;
			}
		}

		if (countOfRemovals == 0)
		{
			cout<<"0"<<endl;
			return 0;
		}

		cout<<"1"<<endl;
		cout<<countOfRemovals<<endl;
		for (int i = 0; i < n; ++i)
		{
			if(removed[i] == true)
				cout<<i+1<<' ';	
		}

	}
	return 0;
}