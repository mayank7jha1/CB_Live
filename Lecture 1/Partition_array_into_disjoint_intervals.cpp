class Solution {
public:
    int partitionDisjoint(vector<int>& a) {
        int n = a.size();
        int length = 0;
        int current_max = a[0], left_max = a[0];

        for (int i = 1; i < n; i++) {
            current_max = max(a[i], current_max);

            if (a[i] < left_max) {
                length = i;
                left_max = current_max;
            }
        }
        return length + 1;
    }
};


// 6 1 4 8 7

// left = 6, 1, 4,
// left_max = 6