class Solution {
private:
    long long dp[31];

    long long _calcFib(int n) {
        if (n <= 1) return n;
        if (dp[n] != -1) return dp[n];
        dp[n] = (long long) _calcFib(n - 1) + _calcFib(n - 2);
        return dp[n];
    }

public:
    int fib(int n) {
        fill(dp, dp + 31, -1);
        return _calcFib(n);
    }
};