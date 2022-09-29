class Solution {
public:
	int lengthOfLIS(vector<int>& nums) {
		int n = nums.size();
		vector<int>dp(n, 1);

		for (int i = 1; i < n; i++) {
			for (int j = 0; j < i; j++) {
				if (num[i] > nums[j] and dp[i] < dp[j] + 1) {
					dp[i] = dp[j] + 1;
				}
			}
		}

		int ans = INT_MIN;
		for (int i = 0; i < n; i++) {
			ans = max(dp[i], ans);
		}
		return ans;
	}
};