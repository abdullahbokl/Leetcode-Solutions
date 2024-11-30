class Solution {
private:
    int dir_r[4] = {0, 0, 1, -1};
    int dir_c[4] = {1, -1, 0, 0};

    void dfs(vector<vector<char>> &grid, int row, int col) {
        // base condition. Here, total row=grid.length, total column= grid[0].length
        if (row < 0 || row >= grid.size() || col < 0 || col >= grid[0].size() || grid[row][col] != '1') {
            return;
        }
        
        // make the cell visited by changing its value from '1' to anything 
        grid[row][col] = 'X';

        // Check in four adjacent neighbors
        for (int i = 0; i < 4; i++) {
            dfs(grid, row + dir_r[i], col + dir_c[i]);
        }

//        dfs(grid, row - 1, col);// check in upper side
//        dfs(grid, row + 1, col);//check in bottm side
//        dfs(grid, row, col - 1);//check in left side
//        dfs(grid, row, col + 1);//check in right side
    }

public:
    int numIslands(vector<vector<char>> &grid) {
        int n = (int) grid.size(), m = (int) grid[0].size();
        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == '1') {
                    ans++;
                    dfs(grid, i, j);
                }
            }
        }
        return ans;
    }
};