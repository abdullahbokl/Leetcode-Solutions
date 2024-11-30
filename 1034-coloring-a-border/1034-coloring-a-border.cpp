class Solution {
private:
    int dir_r[4] = {0, 0, 1, -1};
    int dir_c[4] = {1, -1, 0, 0};

    void dfs(vector<vector<int>> &grid, int row, int col, int newColor, int oldColor, vector<vector<bool>> &vis) {
        vis[row][col] = true;
        for (int i = 0; i < 4; ++i) {
            int newRow = row + dir_r[i], newCol = col + dir_c[i];
            if (newRow < 0 || newRow >= grid.size() || newCol < 0 || newCol >= grid[0].size() || (grid[newRow][newCol] != oldColor and !vis[newRow][newCol])) {
                grid[row][col] = newColor;
                continue;
            }
            if (!vis[newRow][newCol]) {
                dfs(grid, newRow, newCol, newColor, oldColor, vis);
            }
        }
    }

public:
    vector<vector<int>> colorBorder(vector<vector<int>> &grid, int row, int col, int color) {
        int oldColor = grid[row][col];
        vector<vector<bool>> vis(grid.size(), vector<bool> (grid[0].size(), false));
        dfs(grid, row, col, color, oldColor, vis);
        return grid;
    }
};