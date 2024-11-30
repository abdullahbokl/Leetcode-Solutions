class Solution {
private:
    int dir_r[4] = {0, 0, 1, -1};
    int dir_c[4] = {1, -1, 0, 0};

    void dfs(vector<vector<int>> &grid, int row, int col, int oldColor, int newColor) {
        if (row < 0 || row >= grid.size() || col < 0 || col >= grid[0].size() || grid[row][col] != oldColor) {
            return;
        }
        grid[row][col] = newColor;

        for (int i = 0; i < 4; ++i) {
            dfs(grid, row + dir_r[i], col + dir_c[i], oldColor, newColor);
        }
    }

public:
    vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int color) {
        if (image[sr][sc] != color) {
            int oldColor = image[sr][sc];
            dfs(image, sr, sc, oldColor, color);
        }
        return image;
    }
};