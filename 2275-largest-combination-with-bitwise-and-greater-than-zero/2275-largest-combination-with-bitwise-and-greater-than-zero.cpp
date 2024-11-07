class Solution {
public:
    int largestCombination(vector<int> &candidates) {
        int maxFreq = 0;
        for (int i = 0; i < 24; i++) {
            int freq = 0;
            for (int num: candidates) {
                if ((num & (1 << i))) freq++;
            }
            maxFreq = max(maxFreq, freq);
        }
        return maxFreq;
    }
};