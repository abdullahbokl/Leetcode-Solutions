class Solution {
private:
    int dp[1005];

    int _calcMin(vector<int> &cost, int n, int idx) {
        if (idx >= n) return 0;
        if (dp[idx] != -1) return dp[idx];

        dp[idx] = cost[idx] + min(_calcMin(cost, n, idx + 1), _calcMin(cost, n, idx + 2));
        return dp[idx];
    }


public:
    int minCostClimbingStairs(vector<int> &cost) {
        int n = cost.size();
        fill(dp, dp + n, -1);
        int a = _calcMin(cost, n, 0);
        fill(dp, dp + n, -1);
        int b = _calcMin(cost, n, 1);
        return min(a, b);
    }
};