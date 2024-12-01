class Solution {
private:
    const int dx[4] = {-1, 1, 0, 0}; // U, D, L, R
    const int dy[4] = {0, 0, -1, 1};

    int dfs(vector<vector<int>> &grid, int row, int col) {
        if (row < 0 || row >= grid.size() || col < 0 || col >= grid[0].size() || grid[row][col] == 0) {
            return 0;
        }

        int total = grid[row][col];
        grid[row][col] = 0;

        for (int i = 0; i < 4; ++i) {
            total += dfs(grid, row + dx[i], col + dy[i]);
        }

        return total;
    }

public:
    int findMaxFish(vector<vector<int>> &grid) {
        int n = static_cast<int> (grid.size()), m = static_cast<int> (grid[0].size());
        int maxFish = 0;

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (grid[i][j]) {
                    maxFish = max(maxFish, dfs(grid, i, j));
                }
            }
        }

        return maxFish;
    }
};
