class Solution {
public:
    long long pickGifts(vector<int> &gifts, int k) {
        priority_queue<int> pq;
        for (int i: gifts) pq.emplace(i);
        while (k--) {
            int top = pq.top();
            pq.pop();
            top = sqrt(top);
            pq.emplace(top);
        }
        long long sum = 0;
        while (!pq.empty()) {
            sum = sum + pq.top();
            pq.pop();
        }
        return sum;
    }
};
