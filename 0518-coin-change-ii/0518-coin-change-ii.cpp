class Solution {
private:
    vector<vector<int>> dp = vector<vector<int>>(5001, vector<int>(5001, -1));

    int solve(vector<int> &coins, int sz, int amount, int i = 0) {

        if (amount == 0) return 1;
        if (amount < 0 || i == sz) return 0;
        if (dp[i][amount] != -1) return dp[i][amount];

        int ans = 0;
        int take = solve(coins, sz, amount - coins[i], i);
        int leave = solve(coins, sz, amount, i + 1);

        ans += take + leave;

        return dp[i][amount] = ans;
    }

public:
    int change(int amount, vector<int> &coins) {
        return solve(coins, (int) coins.size(), amount);
    }
};
