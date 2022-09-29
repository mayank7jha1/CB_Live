class Solution {
	int stair(vector<int>&cost, int i, int n, int *dp) {
		if (i >= n) {
			return 0;
		}
		if (dp[i] != -1) return dp[i];
		int op1, op2;
		op1 = op2 = INT_MAX;
		op1 = stair(cost, i + 1, n, dp) + cost[i];
		op2 = stair(cost, i + 2, n, dp) + cost[i];
		return dp[i] = min(op1, op2);
	}

public:
	int minCostClimbingStairs(vector<int>& cost) {
		int *dp = new int[cost.size() + 1];
		int n = cost.size();

		for (int i = 0; i < cost.size() + 1; i++) dp[i] = -1;
		int op1 = stair(cost, 0, n, dp);

		for (int i = 0; i < cost.size() + 1; i++) dp[i] = -1;
		int op2 = stair(cost, 1, n, dp);

		return min(op1, op2);
	}
};

class Solution {
public:
	int minCostClimbingStairs(vector<int>& cost) {
		int n = cost.size();
		vector<int>dp = cost;
		for (int i = 2; i < n; i++) {
			dp[i] += min(dp[i - 1], dp[i - 2]);
		}
		return min(dp[n - 1], dp[n - 2]);
	}
};