class Solution {
public:
    int minChanges(string s) {
        int ans = 0, n = (int) s.size();

        for (int i = 0; i + 1 < n; i += 2) {
            if (s[i] != s[i + 1]) ++ans;
        }
        return ans;
    }
};