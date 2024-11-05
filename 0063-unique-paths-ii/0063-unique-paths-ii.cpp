class Solution {
private:
    vector<vector<int>> dp = vector<vector<int>>(101, vector<int>(101, -1));

    int _solve(vector<vector<int>>& obstacleGrid, int n, int m) {

        if (n < 0 or m < 0 or obstacleGrid[n][m] == 1) return 0;
        if (n == 0 and m == 0)   return 1;
        if (dp[n][m] != -1) return dp[n][m];


        return dp[n][m] = _solve(obstacleGrid, n-1, m) + _solve(obstacleGrid, n, m-1);
    }
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        return _solve(obstacleGrid, obstacleGrid.size()-1, obstacleGrid[0].size()-1);
    }
};
