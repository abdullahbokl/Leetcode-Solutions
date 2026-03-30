class Solution {
public:
    int countGoodSubstrings(string s) {
        int size = int(s.size());
        if (size < 3) return 0;

        int ans = 0;
        for (int i = 0; i < size - 2; i++) {
            if (s[i] != s[i + 1] && s[i] != s[i + 2] && s[i + 1] != s[i + 2]) {
                ans++;
            }
        }
        
        return ans;
    }
};