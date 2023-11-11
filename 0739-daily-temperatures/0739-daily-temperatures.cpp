class Solution {
public:
    std::vector<int> dailyTemperatures(std::vector<int>& temperatures) {
        int sz = static_cast<int>(temperatures.size());
        std::vector<int> ans(sz);
        std::stack<std::pair<int, int>> st;  // Stack of pairs (temperature, index)
        
        for (int i = sz - 1; i >= 0; i--) {
            while (!st.empty() && st.top().first <= temperatures[i]) {
                st.pop();
            }
            
            ans[i] = st.empty() ? 0 : st.top().second - i;
            st.push({temperatures[i], i});
        }
        
        return ans;
    }
};





