class Solution {
private:
    vector<int> freq = vector<int>(32, 0);

    void count(int n) {
        for (int i = 0; i < 32; i++) {
            if (n & (1 << i)) freq[i]++;
        }
    }

public:
    int minimumSubarrayLength(vector<int> &nums, int k) {
        int sz = (int) nums.size(), total = 0, ans = INT_MAX;
        for (int i = 0, j = 0; i < sz; ++i) {
            total |= nums[i];
            count(nums[i]);
            while (total >= k and j <= i) {
                ans = min(ans, i - j + 1);
                for (int l = 0; l < 32; l++) {
                    if (nums[j] & (1 << l)) freq[l]--;
                    if (freq[l] == 0) total &= ~(1 << l);
                }
                j++;
            }
        }
        return ans == INT_MAX ? -1 : ans;
    }
};
