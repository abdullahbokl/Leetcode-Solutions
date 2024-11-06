class Solution {
private:
    vector<vector<vector<int>>> dp = vector<vector<vector<int>>>(601, vector<vector<int>>(101, vector<int>(101, -1)));

    int solve(vector<pair<int, int>> &zerosOnes, int sz, int m, int n, int index) {

        if (m == 0 and n == 0 or index == sz) return 0;
        if (dp[index][m][n] != -1) return dp[index][m][n];


        int ans = INT_MIN;
        if (m >= zerosOnes[index].first and n >= zerosOnes[index].second) {
            ans = 1 + solve(zerosOnes, sz, m - zerosOnes[index].first, n - zerosOnes[index].second, index + 1);
        }

        ans = max(ans, solve(zerosOnes, sz, m, n, index + 1));

        return dp[index][m][n] = ans;
    }

public:
    int findMaxForm(vector<string> &strs, int m, int n) {
        vector<pair<int, int>> zerosOnes;
        for (auto &str: strs) {
            int zeros = 0, ones = 0;
            for (auto &ch: str) {
                if (ch == '0') zeros++;
                else ones++;
            }
            zerosOnes.emplace_back(zeros, ones);
        }

        int value = solve(zerosOnes, zerosOnes.size(), m, n, 0);
        return value < 0 ? 0 : value;
    }
};
