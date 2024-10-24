class Solution {
private:
    const int sz = 2e4 + 5;
    int dp[20005];
    map<int, int> freq;

    int _solve(int n) {
        if (n < 0) return 0;

        if (dp[n] != -1) return dp[n];

        int take = -1;
        if (freq[n] != 0) {
            take = n * freq[n] + _solve(n - 2);
        }
        int leave = _solve(n - 1);


        return dp[n] = max(take, leave);
    }

public:
    int deleteAndEarn(vector<int> &nums) {
        memset(dp, -1, sizeof(dp));
        freq.clear();
        int mx = -1;
        for (auto &num: nums) freq[num]++, mx = max(mx, num);
        return _solve(mx);
    }
};