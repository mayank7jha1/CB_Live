class Solution {
public:
	int lengthOfLongestSubstring(string s) {
		unordered_map<int, int>m;

		int ans = 0;
		for (int l = 0, r = 0; r < s.length(); r++) {
			if (m.count(s[r]) == 1) {
				l = max(l, m[s[r]] + 1);
			}

			m[s[r]] = r;
			ans = max(ans, r - l + 1);
		}
		return ans;
	}
};




// abcda

// a=0;
// b=1
// c=2
// d=3
// a

// a===yes:
// l=m[s[r]]=m[a]=0+1===l
// l=1;
// r=4
// 4-1+1=4;