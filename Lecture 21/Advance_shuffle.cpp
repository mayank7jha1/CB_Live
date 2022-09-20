class Solution {
public:
    vector<int> advantageCount(vector<int>& a, vector<int>& c) {
        int n = a.size();
        sort(a.begin(), a.end());
        vector<pair<int, int>>b;//Value,Index:

        for (int i = 0; i < c.size(); i++) {
            b.push_back({c[i], i});
        }

        sort(b.begin(), b.end());
        vector<int>ans(n, -1);
        vector<int>extra;

        int j = 0;
        for (int i = 0; i < n; i++) {
            if (a[i] > b[j].first) {
                ans[b[j].second] = a[i];
                j++;
            } else {
                extra.push_back(a[i]);
            }
        }

        if (extra.size() == 0) {
            return ans;
        }

        j = 0;
        for (int i = 0; i < n; i++) {
            if (a[i] == -1) {
                ans[i] = extra[j];
                j++;
            }
            if (j == extra.size()) {
                break;
            }
        }
        return ans;

    }
};
/*
8 12 25 32

11===8 8 is smaller than 11 sorted baaki saare will greater than 11:
*/
