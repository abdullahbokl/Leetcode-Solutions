class Solution {
public:
    int maxProfit(vector<int> &prices) {
        int currMaxSum = 0, currMinSum = 0, ans = INT_MIN, sz = (int) prices.size();

        for (int i = 1; i < sz; ++i) {
            int temp = currMaxSum + prices[i] - prices[i - 1];

            currMaxSum = max(temp, prices[i] - prices[i - 1]);
            currMinSum = min(currMinSum, prices[i] - prices[i - 1]);
            ans = max(ans, currMaxSum);
        }
        return ans > 0 ? ans : 0;
    }
};