int dir_r[] = {0, 1, 0, -1};
int dir_c[] = {1, 0, -1, 0};
class Solution {
public:
    bool exist(vector<vector<char>> &board, string word) {
        int n = static_cast<int>(board.size());
        int m = static_cast<int>(board[0].size());
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        string temp = word;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (word.back() == board[i][j]) {
                    if (dfs(board, word, i, j, visited)) {
                        return true;
                    }
                    visited = vector<vector<bool>>(n, vector<bool>(m, false));
                    word = temp;
                }
            }
        }

        return false;
    }

private:
    bool dfs(vector<vector<char>> &board, string &word, int row, int col, vector<vector<bool>> &visited) {
        if (word.empty()) return true;
        if (row < 0 || row >= board.size() || col < 0 || col >= board[0].size() || visited[row][col] ||
            board[row][col] != word.back()) {
            return false;
        }

        char x = word.back();
        word.pop_back();
        visited[row][col] = true;

        for (int k = 0; k < 4; k++) {
            if (dfs(board, word, row + dir_r[k], col + dir_c[k], visited)) return true;
        }
        visited[row][col] = false;
        word.push_back(x);

        return false;
    }

};