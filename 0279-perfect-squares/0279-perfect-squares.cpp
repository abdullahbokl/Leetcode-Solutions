class Solution {

private:

    vector<int> dp = vector<int>(10001, -1);

    int solve(int n) {
        if (n == 0) return 0;
        if (n < 0) return INT_MAX;
        if (dp[n] != -1) return dp[n];


        int ans = INT_MAX;
        for (int j = 1; j <= 100; ++j) {
            if (j * j > n) break;
            int temp = solve(n - j * j);
            ans = min(ans, temp + 1);
        }

        return dp[n] = ans;
    }

public:
    int numSquares(int n) {
        return solve(n);
    }
};
