class Solution {
public:
    long long maxSpending(vector<vector<int>> &values) {
        // min heap >> value {row, col}
        priority_queue<pair<int, vector<int>>, vector<pair<int, vector<int>>>, greater<>> pq;
        int lastCol = static_cast<int>(values.back().size()) - 1;
        for (int i = 0; i < values.size(); i++) {
            pq.emplace(values[i][lastCol], vector<int>{i, lastCol});
        }
        long long ans = 0, value;
        int day = 1, row, col;
        while (!pq.empty()) {
            value = pq.top().first, row = pq.top().second[0], col = pq.top().second[1];
            pq.pop();
            ans += value * day++;
            if (col > 0) {
                col--;
                pq.emplace(values[row][col], vector<int>{row, col});
            }
        }

        return ans;
    }
};
