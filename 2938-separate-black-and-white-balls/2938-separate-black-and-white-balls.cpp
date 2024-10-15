class Solution {
public:
    long long minimumSteps(string s) {
        int lastWhite = 0;
        for (int i = s.size() - 1; i >= 0; --i) {
            if (s[i] == '0') {
                lastWhite = i;
                break;
            };
        }

        long long ans = 0;

        for (int i = lastWhite - 1; i >= 0; --i) {
            if (s[i] == '1') ans += lastWhite - i, lastWhite--;
        }

        return ans;
    }

};
