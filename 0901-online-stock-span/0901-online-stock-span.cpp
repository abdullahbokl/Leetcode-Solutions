class StockSpanner {
public:
    StockSpanner() {
        ans = 1;
        currentIdx = 0;
        vec.clear();
        st = stack<int>();
    }

    int next(int price) {

        vec.push_back(price);
        while (!st.empty() and vec[st.top()] <= price) st.pop();
        ans = st.empty() ? currentIdx + 1 : currentIdx - st.top();
        st.push(currentIdx);
        currentIdx++;
        return ans;
    }

private:
    int ans = 1, currentIdx = 0;
    vector<int> vec;
    stack<int> st;
};
