class Solution {
public:
    int minSubArrayLen(int target, vector<int> &nums) {
        int n = (int) nums.size(), ans = INT_MAX, sum = 0, i = 0;
        for (int j = 0; j < n; j++) {
            sum += nums[j];
            while (sum >= target) {
                ans = min(ans, j - i + 1);
                sum -= nums[i++];
            }
        }
        return (ans != INT_MAX) ? ans : 0;
    }
};