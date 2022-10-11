class Solution {
public:
	unordered_map<string, bool>h;
	int *dp;
	bool Solve(string s, int pos) {

		if (pos == s.length()) {
			return 1;
		}
		if (dp[pos] != -1) {
			return dp[pos];
		}
		for (int end = pos + 1; end <= s.length(); end++) {
			string x = s.substr(pos, end - pos);
			if (h.count(x) and Solve(s, end)) {
				return dp[pos] = 1;
			}
		}
		return dp[pos] = 0;
	}

	bool wordBreak(string s, vector<string>& wordDict) {
		for (int i = 0; i < wordDict.size(); i++) {
			h.insert({wordDict[i], true});
		}

		dp = new int[s.length() + 1];
		for (int i = 0; i <= s.length(); i++) dp[i] = -1;

		return Solve(s, 0);
	}
};


/*substr: function: subtring substr(pos,end-pos);

m*/