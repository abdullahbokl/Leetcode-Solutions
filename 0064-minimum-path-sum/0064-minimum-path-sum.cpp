const int sz = 201;

class Solution {
    int dp[sz][sz];

    int _solve(vector<vector<int>> &grid, int row, int col) {
        if (row < 0 || col < 0) return INT_MAX;
        if (row == 0 && col == 0) return grid[0][0];
        if (dp[row][col] != -1) return dp[row][col];
        return dp[row][col] = grid[row][col] + min(_solve(grid, row - 1, col), _solve(grid, row, col - 1));
    }

public:
    int minPathSum(vector<vector<int>> &grid) {
        fill(&dp[0][0], &dp[0][0] + sz * sz, -1);
        return _solve(grid, grid.size() - 1, grid[0].size() - 1);
    }
};