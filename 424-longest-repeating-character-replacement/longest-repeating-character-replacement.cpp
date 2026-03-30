class Solution {
public:
    int characterReplacement(string s, int k) {
        int size = int(s.size());
        int mx = 0;
        map<char, int> freq;
        int mx_freq = 0;
        for (int right = 0, left = 0; right < size; right++) {
            freq[s[right]]++;
            mx_freq = max(mx_freq, freq[s[right]]);
            int length = right - left + 1;
            int flips = length - mx_freq;
            if (flips > k) {
                freq[s[left]]--;
                left++;
            } else {
                mx = max(mx, length);
            }
        }
        return mx;
    }
};