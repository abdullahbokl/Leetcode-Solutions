class Solution {
private:
    const int MOD = 1e9 + 7;
    vector<int> dp = vector<int>(1e5 + 1, -1);

    int solve(int n, int low, int high, int zero, int one) {
        // base case
        if (n > high) return 0;
        if (dp[n] != -1) return dp[n];

        // counter
        int cnt = 0;
        if (n >= low and n <= high) cnt = 1;

        // recursion call
        cnt = cnt + solve(n + zero, low, high, zero, one) % MOD;
        cnt = (cnt % MOD + solve(n + one, low, high, zero, one) % MOD) % MOD;

        return dp[n] = cnt;
    }

public:
    int countGoodStrings(int low, int high, int zero, int one) {
        return solve(0, low, high, zero, one);
    }
};
