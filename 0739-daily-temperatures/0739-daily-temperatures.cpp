class Solution {
public:
    vector<int> dailyTemperatures(vector<int> &temperatures) {
        int sz = (int) temperatures.size();
        vector<int> ans(sz);
        stack<int> st;
        for (int i = sz - 1; i >= 0; i--) {
            while (!st.empty() && temperatures[st.top()] <= temperatures[i]) {
                st.pop();
            }
            ans[i] = st.empty() ? 0 : st.top() - i;
            st.push(i);
        }
        return ans;
    }
};