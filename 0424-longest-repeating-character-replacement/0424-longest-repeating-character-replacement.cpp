class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = (int) s.size(), left = 0, right = 0, max_freq = 0, ans = 0;
        vector<int> freq(26, 0);
        while (right < n) {
            freq[s[right] - 'A']++;
            max_freq = max(max_freq, freq[s[right] - 'A']);
            if (right - left + 1 - max_freq > k) freq[s[left++] - 'A']--;
            ans = max(ans, right - left + 1);
            right++;
        }
        return ans;
    }
};