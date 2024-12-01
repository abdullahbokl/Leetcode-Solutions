class Solution {
private:
    vector<vector<int>> dp = vector<vector<int>>(500, vector<int>(1001, -1));

    int rec(vector<int> &slices, int idx, int lastIdx, int remaining) {
        if (idx > lastIdx || !remaining) return 0;
        if (dp[idx][remaining] != -1) return dp[idx][remaining];

        int eat = slices[idx] + rec(slices, idx + 2, lastIdx, remaining - 1);
        int lev = 0 + rec(slices, idx + 1, lastIdx, remaining);

        return dp[idx][remaining] = max(lev, eat);
    }

public:
    int maxSizeSlices(vector<int> &slices) {
        int n3 = static_cast<int>(slices.size());
        int sz = n3 / 3;

        int mx = rec(slices, 0, n3 - 2, sz);
        dp = vector<vector<int>>(500, vector<int>(1001, -1));
        mx = max(mx, rec(slices, 1, n3 - 1, sz));

        return mx;
    }
};
