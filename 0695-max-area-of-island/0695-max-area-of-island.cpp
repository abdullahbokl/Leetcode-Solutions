int dir_r[] = {0, 1, 0, -1};
int dir_c[] = {1, 0, -1, 0};
class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>> &grid) {
        int n = static_cast<int>(grid.size());
        int m = static_cast<int>(grid[0].size());
        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; ++j) {
                if (grid[i][j] == 1) {
                    ans = max(ans, dfs(grid, i, j));
                }
            }
        }
        return ans;
    }

private:
    int dfs(vector<vector<int>> &grid, int i, int j) {
        if (i < 0 || j < 0 || i >= static_cast<int>(grid.size()) || j >= static_cast<int>(grid[0].size()) ||
            !grid[i][j]) {
            return 0;
        }

        grid[i][j] = 0;
        int ans = 1;
        for (int k = 0; k < 4; ++k) {
            ans += dfs(grid, i + dir_r[k], j + dir_c[k]);
        }
        return ans;
    }
};
