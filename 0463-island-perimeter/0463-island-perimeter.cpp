class Solution {
private:
    int dir_r[4] = {0, 0, 1, -1};
    int dir_c[4] = {1, -1, 0, 0};

    int dfs(vector<vector<int>> &grid, int row, int col) {
        if (row < 0 || row >= grid.size() || col < 0 || col >= grid[0].size() || grid[row][col] == 0) {
            return 1;
        }
        if (grid[row][col] == -1) return 0;

        grid[row][col] = -1;
        int ans = 0;
        for (int i = 0; i < 4; ++i) {
            ans += dfs(grid, row + dir_r[i], col + dir_c[i]);
        }

        return ans;
    }


public:
    int islandPerimeter(vector<vector<int>> &grid) {
        int n = (int) grid.size(), m = (int) grid[0].size();
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (grid[i][j] == 1) {
                    return dfs(grid, i, j);
                }
            }
        }
        return 0;
    }
};
