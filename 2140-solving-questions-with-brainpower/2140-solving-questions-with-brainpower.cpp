class Solution {
private:
    vector<long long> dp = vector<long long>(1e5 + 1, -1);

    long long solve(vector<vector<int>> &questions, int sz, int i = 0) {
        if (i >= sz) return 0;
        if (dp[i] != -1) return dp[i];

        long long skip = solve(questions, sz, i + 1);
        long long take = questions[i][0] + solve(questions, sz, i + 1 + questions[i][1]);
        return dp[i] = max(skip, take);
    }

public:
    long long mostPoints(vector<vector<int>> &questions) {
        return solve(questions, questions.size());
    }
};
