class Solution {
private:
    vector<vector<int>> dp = vector<vector<int>>(301, vector<int>(301, -1));

    int solve(vector<vector<char>> &matrix, int r, int c) {

        if (r >= matrix.size() or c >= matrix[0].size()) return 0;
        if (dp[r][c] != -1) return dp[r][c];


        int down = solve(matrix, r + 1, c);
        int right = solve(matrix, r, c + 1);
        int diagonal = solve(matrix, r + 1, c + 1);

        dp[r][c] = 0;
        if (matrix[r][c] == '1') {
            dp[r][c] = 1 + min({down, right, diagonal});
        }
        
        return dp[r][c];
    }

public:
    int maximalSquare(vector<vector<char>> &matrix) {
        solve(matrix, 0, 0);
        int mx = 0;
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[0].size(); j++) {
                mx = max(mx, dp[i][j]);
                cout << dp[i][j] << " ";
            }
            cout << endl;
        }
        return mx * mx;
    }
};
