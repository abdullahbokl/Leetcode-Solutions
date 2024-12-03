class Solution {
public:
    string addSpaces(string s, vector<int> &spaces) {
        int l = 0, sz = static_cast<int>(s.size()), n = static_cast<int>(spaces.size());
        string ans = "";
        for (int i = 0; i < sz; ++i) {
            if (l < n and spaces[l] == i) {
                ans += " ";
                l++;
            }
            ans += s[i];
        }
        return ans;
    }
};
