class Solution {
private:
    int dp[101];

    int _solve(vector<int> &nums, int idx) {
        if (idx >= nums.size()) return 0;
        if (dp[idx] != -1) return dp[idx];

        dp[idx] = max(nums[idx] + _solve(nums, idx + 2), _solve(nums, idx + 1));
        return dp[idx];
    }

public:
    int rob(vector<int> &nums) {
        fill(dp, dp + 101, -1);
        return _solve(nums, 0);
    }
};
