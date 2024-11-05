class Solution {
private:

    vector<vector<int>> dp = vector<vector<int>>(101, vector<int>(101, INT_MAX));

    int solve(vector<vector<int>> &matrix, int r, int c) {
        if (dp[r][c] != INT_MAX) return dp[r][c];
        if (r == matrix.size()) return 0;

        int down = INT_MAX, downRight = INT_MAX, downLeft = INT_MAX;
        down = solve(matrix, r + 1, c);
        if (c + 1 < matrix[0].size())   downRight = solve(matrix, r + 1, c + 1);
        if (c > 0)                      downLeft = solve(matrix, r + 1, c - 1);

        return dp[r][c] = matrix[r][c] + min(down, min(downRight, downLeft));
    }

public:
    int minFallingPathSum(vector<vector<int>> &matrix) {
        int ans = INT_MAX;
        for (int i = 0; i < matrix.size(); ++i) {
            ans = min(ans, solve(matrix, 0, i));
        }
        return ans;
    }
};
