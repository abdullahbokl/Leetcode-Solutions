class Solution {
private:
    int dp[50];

    int _steps(int n) {
        if (n < 0) return 0;
        if (n == 0) return 1;

        if (dp[n] != -1) return dp[n];

        dp[n] = _steps(n - 1) + _steps(n - 2);
        return dp[n];
    }

public:
    int climbStairs(int n) {

        fill(dp, dp + 50, -1);

        return _steps(n);

    }
};