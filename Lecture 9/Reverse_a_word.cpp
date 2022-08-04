class Solution {
public:
    string reverseWords(string s) {
        vector<string>v;

        char *token = strtok((char*)s.c_str(), " ");

        while (token != NULL) {
            v.push_back(token);
            token = strtok(NULL, " ");
        }

        reverse(v.begin(), v.end());

        string ans = "";
        for (int i = 0; i < v.size(); i++) {
            if (i == v.size() - 1) {
                ans = ans + v[i];
            } else {
                ans = ans + v[i] + " ";
            }
        }
        return ans;
    }
};


// string class ke ander ek function