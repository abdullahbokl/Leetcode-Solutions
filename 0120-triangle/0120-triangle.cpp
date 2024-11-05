class Solution {
private:

    vector<vector<int>> dp = vector<vector<int>>(201, vector<int>(201, -1));

    int solve(vector<vector<int>> &triangle, int i = 0, int j = 0) {

        if (i == triangle.size()) return 0;
        if (dp[i][j] != -1) return dp[i][j];


        return dp[i][j] = triangle[i][j] + min(solve(triangle, i + 1, j), solve(triangle, i + 1, j + 1));
    }

public:
    int minimumTotal(vector<vector<int>> &triangle) {
        return solve(triangle);
    }
};
