class Solution {
public:
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
        vector<int> ans;
        vector<int> prices;
        vector<int> maxBeautySoFar(items.size() + 1);

        sort(items.begin(), items.end());

        for (const vector<int>& item : items)
            prices.push_back(item[0]);

        for (int i = 0; i < items.size(); ++i)
            maxBeautySoFar[i + 1] = max(maxBeautySoFar[i], items[i][1]);

        for (const int query : queries) {
            int i = upper_bound(prices.begin(), prices.end(), query) - prices.begin();
            ans.push_back(maxBeautySoFar[i]);
        }

        return ans;
    }
};