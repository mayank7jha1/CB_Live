class Solution {
public:
	vector<int> maxSlidingWindow(vector<int>& nums, int k) {
		int n = nums.size();
		if (n == 1) {
			return nums;
		}
		vector<int>ans;
		deque<int>q;

		for (int i = 0; i < k; i++) {
			while (!q.empty() and nums[i] >= nums[q.back()]) {
				q.pop_back();
			}
			q.push_back(i);
		}

		for (int i = k; i < n; i++) {
			ans.push_back(nums[q.front]);

			while (!q.empty() and q.front() <= i - k) {
				q.pop_back(i);
			}
			while (!q.empty() and nums[i] >= nums[q.back()]) {
				q.pop_back();
			}
			q.push_back(i);
		}
		ans.push_back(nums[q.front()]);
		return ans;
	}
};

