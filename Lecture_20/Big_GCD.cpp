/*input
0 98789675643215678890987654321234567776567788893374782227464722934643728293475692292111023874
*/
#include <bits/stdc++.h>
using namespace std;
#define int long long
//values
#define MAX 100005
#define inf LLONG_MAX
#define MIN INT_MIN
#define PIE 3.141592653589793238

int mod = 1e10 + 7;
/*int powmod(int a, int b) {
    int res = 1;
    if (a >= mod) {
        a %= mod;
    }
    for (; b; b >>= 1) {
        if (b & 1) {
            res = res * a;
        }
        if (res >= mod) {
            res %= mod;
        }
        a = a * a;
        if (a >= mod) {
            a %= mod;
        }
    }
    return res;
}*/

/*..................................................................................................................................*/


int gcd(int a , int b) {
	return b == 0 ? a : gcd(b, a % b);
}


int32_t main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n, n1, r = 0;
	string a; //storing large number in the form of string
	cin >> n >> a;
	// cout << n << " ";
	if (n == 0) {
		cout << a; //b==0 print a (comparing with standard gcd approach)
	} else {          //else calculate a%b first
		for (int i = 0; i < a.size(); i++) {
			n1 = r * 10 + (a[i] - 48); //char by char making integer from string and taking modulus with smaller number
			//cout << n1 << " ";
			r = n1 % n;
			//cout << r << endl;
		}
		cout << gcd(n, r);  //Now Calculating gcd with standard approach
	}
	return 0;
}


/*
'2' integer 2 kaise banau:  '2' - '0' = 2;

50 - 48 = 2;*/