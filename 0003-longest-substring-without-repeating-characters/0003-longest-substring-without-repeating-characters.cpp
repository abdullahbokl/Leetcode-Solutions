class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        int sz = (int) s.size(), left = 0, right = 0, dup = 0;
        // 128 ASCII code for all the characters (letters, numbers, symbols, and spaces)
        vector<int> freq(128);

        while (right < sz) {
            freq[s[right]]++;
            // use "== 2" instead of "> 1" to avoid the case of "aaa"
            if (freq[s[right]] == 2) dup++;
            if (dup) dup -= (--freq[s[left++]] == 1);
            right++;
        }

        return right - left;
    }
};