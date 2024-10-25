class Solution {
public:
    int maxSubarraySumCircular(vector<int> &nums) {
        int mxSum = 0, mnSum = 0, mx = INT_MIN, mn = INT_MAX, total = 0;

        for (const int num: nums) {
            total += num;

            mxSum = max(num, mxSum + num);
            mnSum = min(num, mnSum + num);

            mx = max(mx, mxSum);
            mn = min(mn, mnSum);
        }

        return (mx > 0 ? max(mx, total - mn) : mx);
    }
};