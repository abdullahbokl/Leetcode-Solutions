class Solution {
private:
    const int dx[4] = {-1, 1, 0, 0}; // U, D, L, R
    const int dy[4] = {0, 0, -1, 1};

    bool isValid(int row, int col, vector<vector<int>> &matrix) {
        return row >= 0 && row < matrix.size() && col >= 0 && col < matrix[0].size();
    }

    int dfs(vector<vector<int>> &matrix, int row, int col, vector<vector<int>> &dp) {
        if (!isValid(row, col, matrix)) return 0;
        if (dp[row][col] != -1) return dp[row][col];

        int mx = 0;
        for (int i = 0; i < 4; ++i) {
            int newRow = row + dx[i], newCol = col + dy[i];
            if (!isValid(newRow, newCol, matrix) || matrix[newRow][newCol] <= matrix[row][col]) continue;
            mx = max(mx, dfs(matrix, row + dx[i], col + dy[i], dp));
        }

        dp[row][col] = ++mx;
        return mx;
    }

public:
    int longestIncreasingPath(vector<vector<int>> &matrix) {
        int n = static_cast<int>(matrix.size()), m = static_cast<int>(matrix[0].size());
        int ans = 0;

        vector<vector<int>> dp(n, vector<int>(m, -1));

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                ans = max(ans, dfs(matrix, i, j, dp));
            }
        }

        return ans;
    }
};
