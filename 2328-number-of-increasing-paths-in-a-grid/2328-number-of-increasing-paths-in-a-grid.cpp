class Solution {
private:
    const int MOD = 1e9 + 7;
    const int dx[4] = {-1, 1, 0, 0}; // U, D, L, R
    const int dy[4] = {0, 0, -1, 1};

    bool isValid(int row, int col, vector<vector<int>> &matrix) {
        return row >= 0 && row < matrix.size() && col >= 0 && col < matrix[0].size();
    }


    int dfs(vector<vector<int>> &matrix, int row, int col, vector<vector<int>> &dp) {
        if (dp[row][col] != -1) return dp[row][col];

        int ans = 1;
        for (int i = 0; i < 4; i++) {
            int newRow = row + dx[i];
            int newCol = col + dy[i];
            if (isValid(newRow, newCol, matrix) && matrix[row][col] < matrix[newRow][newCol]) {
                ans = (ans + dfs(matrix, newRow, newCol, dp)) % MOD;
            }
        }

        return dp[row][col] = ans;
    }

public:
    int countPaths(vector<vector<int>> &grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        long long ans = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                ans = (ans + dfs(grid, i, j, dp)) % MOD;
            }
        }


        return ans;
    }
};
