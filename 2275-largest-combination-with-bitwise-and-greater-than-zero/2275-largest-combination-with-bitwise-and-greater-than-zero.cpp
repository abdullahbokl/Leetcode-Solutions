class Solution {
public:
    int largestCombination(vector<int> &candidates) {

        vector<int> freq(24, 0);

        for (int num: candidates) {
            for (int i = 0; i < 24; ++i) {
                if (num & (1 << i)) {
                    freq[i]++;
                }
            }
        }

        // return the max in freq
        int res = freq[0];
        for (int i = 1; i < 24; ++i) res = max(res, freq[i]);

        return res;
    }
};