class Solution {
private:
    vector<vector<long long>> dp = vector<vector<long long>>(13, vector<long long>(10001, -1));

    long long solve(vector<int> &coins, int sz, int amount, int i = 0) {

        if (amount == 0) return 0;
        if (i == sz) return INT_MAX;
        if (dp[i][amount] != -1) return dp[i][amount];


        long long take = INT_MAX;

        if (coins[i] <= amount) {
            take = 1 + solve(coins, sz, amount - coins[i], i);
        }
        long long leave = solve(coins, sz, amount, i + 1);

        long long ans = min(take, leave);

        return dp[i][amount] = ans;
    }

public:
    int coinChange(vector<int> &coins, int amount) {
        int ans = solve(coins, coins.size(), amount);
        return ans == INT_MAX ? -1 : ans;
    }
};
