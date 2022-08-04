class Solution {
public:
	int longestConsecutive(vector<int>& nums) {
		unordered_set<int>s; //O(1);
		int count = 0;
		int ans = 0;
		for (auto x : nums) {
			s.insert(x);
		}

		for (int i = 0; i < nums.size(); i++) {
			if (s.find(nums[i] - 1) != s.end()) {
				continue;
			} else {
				//This is the starting point of the subsequence
				count = 0;
				int x = nums[i];
				while (s.count(x) == 1) {
					x++;
					count++;
				}
				ans = max(count, ans);
			}
		}
		return ans;
	}
};




// find function in map and set will give you the iterater
// or the address of the blocks where the element is found and lets say
// if the element is not found it will give you the last block
// which is .end();

// count function gives or returns true or false i.e boolean
// value if the element exits or not.