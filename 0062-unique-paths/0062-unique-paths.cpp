class Solution {
    int dp[101][101];

    int _solve(int m, int n) {
        if (m == 1 and n == 1) return 1;
        if (m < 1 || n < 1) return 0;

        if (dp[m][n] != -1) return dp[m][n];

        return dp[m][n] = _solve(m - 1, n) + _solve(m, n - 1);
    }

public:
    int uniquePaths(int m, int n) {
        fill(&dp[0][0], &dp[0][0] + 101 * 101, -1);
        return _solve(m, n);
    }
};