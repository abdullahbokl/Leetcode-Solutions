class Solution {
public:
    vector<int> finalPrices(vector<int> &prices) {
        int sz = static_cast<int>(prices.size());
        stack<int> st;
        vector<int> ans(sz);
        for (int i = sz - 1; i >= 0; --i) {
            while (!st.empty() and prices[st.top()] > prices[i]) st.pop();
            ans[i] = prices[i] - (st.empty() ? 0 : prices[st.top()]);
            st.push(i);
        }
        return ans;
    }
};