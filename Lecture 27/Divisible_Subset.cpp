class Solution {
public:
	unordered_map<int, vector<int>>h;

	vector<int>Solve(int index, vector<int>& nums) {
		if (h.count(index) == 1) {
			return h[index];
		}
		vector<int>ans;
		for (int j = 0; j < index; j++) {
			if (nums[index] % nums[j] == 0) {
				auto x = Solve(j, nums);
				if (x.size() > ans.size()) {
					ans = x;
				}
			}
		}
		ans.push_back(nums[index]);
		return ans;
	}

	vector<int> largestDivisibleSubset(vector<int>& nums) {
		int n = nums.size();
		sort(nums.begin(), nums.end());
		vector<int>ans;

		for (int i = 0; i < n; i++) {
			auto x = Solve(i, nums);
			if (x.size() > ans.size()) {
				ans = x;
			}
		}
		return ans;
	}
};




