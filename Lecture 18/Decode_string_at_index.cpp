class Solution {
public:
    string decodeAtIndex(string a, int k) {
        stack<pair<string, long long>>s;

        for (int i = 0; i < a.length(); i++) {
            string x = "";
            while (i < a.length() and (a[i] > '9' or a[i] < '0')) {
                x += a[i];
                i++;
            }
            long long l;
            if (i == a.length()) {
                l = (x.length() + (s.empty() ? 0 : s.top().second));
            } else {
                l = (x.length() + (s.empty() ? 0 : s.top().second)) * (a[i] - '0');
            }
            s.push({x, l});
            if (l >= k) {
                break;
            }
        }

        while (!s.empty()) {
            auto p = s.top();
            string x = p.first;
            long long l = p.second;
            s.pop();

            k = k % (x.length() + (s.empty() ? 0 : s.top().second));
            if (k == 0) {
                k = (x.length() + (s.empty() ? 0 : s.top().second));
            }

            if (s.empty()) {
                string ans = "";
                ans += x[k - 1];
                return ans;
            }

            if (k > s.top().second) {
                string ans = "";
                ans += x[k - s.top().second - 1];
                return ans;
            }
        }
        return "";
    }
};

