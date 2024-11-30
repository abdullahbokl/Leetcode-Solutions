class Solution {
private:
    int dir_r[4] = {0, 0, 1, -1};
    int dir_c[4] = {1, -1, 0, 0};

    void dfs(vector<vector<char>> &grid, int row, int col) {
        if (row < 0 || row >= grid.size() || col < 0 || col >= grid[0].size() || grid[row][col] == '.') {
            return;
        }

        grid[row][col] = '.';

        for (int i = 0; i < 4; ++i) {
            dfs(grid, row + dir_r[i], col + dir_c[i]);
        }
    }


public:
    int countBattleships(vector<vector<char>> &board) {
        int n = (int) board.size(), m = (int) board[0].size(), ans = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (board[i][j] == 'X') {
                    ans++;
                    dfs(board, i, j);
                }
            }
        }
        return ans;
    }
};
