class Solution {
public:
    long long maxKelements(vector<int> &nums, int k) {
        priority_queue<int> pq;
        for (int &num: nums) pq.emplace(num);

        long long total = 0;

        while (k--) {
            int temp = pq.top();
            pq.pop();
            total += temp;
            pq.emplace(ceil(temp / 3.0));
        }

        return total;
    }
};
