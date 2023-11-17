class MinStack {
public:
    MinStack() {
        st = stack<int>();
        minSt = stack<int>();
    }

    void push(int val) {
        st.push(val);
        if (minSt.empty() || val <= minSt.top()) minSt.push(val);
    }

    void pop() {
        if (st.top() == minSt.top()) minSt.pop();
        st.pop();
    }

    int top() {
        return st.top();
    }

    int getMin() {
        return minSt.top();
    }

private:
    stack<int> st;
    stack<int> minSt;
};