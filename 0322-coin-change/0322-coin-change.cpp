class Solution {
private:
    vector<vector<long long>> dp = vector<vector<long long>>(13, vector<long long>(10001, -1));
    long long solve(vector<int>& coins, int sz, int amount) {

        if (amount == 0)    return 0;
        if (amount < 0)    return INT_MAX;



        long long ans = INT_MAX;
        for (int i = 0; i < sz; ++i) {
            if (dp[i][amount] != -1) {
                ans = min(ans, dp[i][amount]);
                continue;
            }
            ans = min(ans, 1 + solve(coins, sz, amount - coins[i]));
            dp[i][amount] = ans;
        }

        return ans;
    }
public:
    int coinChange(vector<int>& coins, int amount) {
        int ans = solve(coins, coins.size(), amount);
        return ans == INT_MAX ? -1 : ans;
    }
};
