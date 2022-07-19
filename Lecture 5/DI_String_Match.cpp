class Solution {
public:
    vector<int> diStringMatch(string s) {
        vector<int>ans;
        if (s.length() == 0) {
            return ans;
        }
        int largest = s.length();
        int smallest = 0;

        for (int i = 0; i < s.length(); i++) {
            if (s[i] == 'I') {
                ans.push_back(smallest++);
            } else {
                ans.push_back(largest--);
            }
        }
        ans.push_back(smallest);
        return ans;
    }
};