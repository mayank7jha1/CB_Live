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
        int n, m;
        cin>>n>>m;

        string s, t;
        cin>>s>>t;

        int leftmost[m];
        int j = 0;
        for (int i = 0; i < n; ++i){
            if(j < m and s[i] == t[j]){
                leftmost[j] = i;
                j++;
            }
        }

        int rightmost[m];
        j = m-1;
        for (int i = n - 1; i >= 0; --i){
            if(j >= 0 and s[i] == t[j]){
                rightmost[j] = i;
                j--;
            }
        }

        int ans = 1;
        for (int i = 1; i < m; ++i){
            ans = max(ans, rightmost[i] - leftmost[i-1]);
        }

        cout<<ans;
    }
    return 0;
}