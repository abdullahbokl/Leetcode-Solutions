class Solution {
private:
    vector<vector<int>> dp = vector<vector<int>>(5001, vector<int>(5001, -1));

    int solve(vector<int> &coins, int sz, int amount) {

        if (amount == 0) return 1;
        if (amount < 0) return 0;


        int ans = 0;
        for (int j = 0; j < sz; ++j) {
            if (amount - coins[j] < 0) continue;
            if (dp[j][amount - coins[j]] != -1) {
                ans += dp[j][amount - coins[j]];
                continue;
            }
            int take = solve(coins, sz, amount - coins[j]);
            ans += take;
            dp[j][amount - coins[j]] = take;
        }

        return ans;
    }

public:
    int combinationSum4(vector<int>& nums, int target) {
        return solve(nums, (int) nums.size(), target);
    }
};