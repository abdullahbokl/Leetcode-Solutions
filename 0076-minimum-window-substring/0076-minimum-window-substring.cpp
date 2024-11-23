class Solution {
private:
    bool isValid(vector<int> &sFreq, vector<int> &tFreq) {
        for (int i = 0; i < 128; i++) {
            if (sFreq[i] < tFreq[i]) return false;
        }
        return true;
    }

public:
    string minWindow(string s, string t) {
        int n = (int) s.size(), m = (int) t.size();
        vector<int> tFreq(128, 0), sFreq(128, 0);
        for (char c: t) tFreq[c]++;

        int l = 0, r = 0, ans = INT_MAX, begin = 0;
        char cr;
        while (r < n) {
            sFreq[s[r]]++;
            while (isValid(sFreq, tFreq) and l <= r) {
                if (r - l + 1 < ans) {
                    ans  = min(ans, r - l + 1);
                    begin = l;
                }
                cr = s[l];
                if (sFreq[cr] - 1 < tFreq[cr]) break;
                sFreq[s[l++]]--;
            }
            r++;
        }

        return ans == INT_MAX ? "" : s.substr(begin, ans);
    }
};
