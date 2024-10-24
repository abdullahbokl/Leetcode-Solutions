class Solution {
private:
    int dp[50];
public:
    int climbStairs(int n) {
        dp[0] = 1;

        for (int i = 1; i <= n; ++i) {
            if (i - 2 < 0) dp[i] = dp[i - 1];
            else dp[i] = dp[i - 1] + dp[i - 2];
        }

        return dp[n];
    }
};