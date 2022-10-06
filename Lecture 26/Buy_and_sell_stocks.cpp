class Solution {
public:
	int maxProfit(vector<int>& prices) {
		if (prices.size() <= 1) {
			return 0;
		}

		int n = prices.size();
		int left[200001] = {0};
		int right[200001] = {0};


		int min_till_now = prices[0];

		for (int i = 1; i < n; i++) {
			left[i] = max(left[i - 1], prices[i] - min_till_now);
			min_till_now = min(min_till_now, prices[i]);
		}

		int max_till_now = prices[n - 1];

		for (int i = n - 2; i >= 0; i--) {
			right[i] = max(right[i + 1], max_till_now - prices[i]);
			max_till_now = max(max_till_now, prices[i]);
		}

		int ans = 0;
		for (int i = 0; i < n - 1; i++) {
			ans = max(left[i] + right[i + 1], ans);
		}

		ans = max({ans, left[n - 1], right[0]});
		return ans;
	}
};