class Solution {
private:
    int dir_r[4] = {0, 0, 1, -1};
    int dir_c[4] = {1, -1, 0, 0};

    void dfs(vector<vector<char>> &grid, int row, int col) {
        if (row < 0 || row >= grid.size() || col < 0 || col >= grid[0].size() || grid[row][col] != 'O') {
            return;
        }

        grid[row][col] = 'A';

        for (int i = 0; i < 4; ++i) {
            dfs(grid, row + dir_r[i], col + dir_c[i]);
        }

    }

public:
    void solve(vector<vector<char>> &board) {
        int n = (int) board.size(), m = (int) board[0].size();
        for (int i = 0; i < m; ++i) {
            dfs(board, 0, i);
            dfs(board, n - 1, i);
        }
        for (int i = 0; i < n; ++i) {
            dfs(board, i, 0);
            dfs(board, i, m - 1);
        }

        for (auto &row: board) {
            for (auto &cell: row) {
                if (cell == 'A') cell = 'O';
                else cell = 'X';
            }
        }
    }
};