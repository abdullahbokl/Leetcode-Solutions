class Solution {
public:
    long long minimumSteps(string s) {
        long long ans = 0;
        int ones = 0;

        for (const char c: s) {
            c == '1' ? ++ones : ans += ones;
        }

        return ans;
    }
};