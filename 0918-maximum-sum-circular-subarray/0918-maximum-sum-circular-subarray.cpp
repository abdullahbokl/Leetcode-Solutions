class Solution {
public:
    int maxSubarraySumCircular(vector<int> &nums) {
        int currMinSum = 0, currMaxSum = 0, ans = INT_MIN, globalMin = INT_MAX, sz = (int) nums.size(), total = 0;

        for (int i = 0; i < sz; ++i) {
            total += nums[i];
            int temp = currMaxSum + nums[i];

            currMaxSum = max({temp, currMinSum + nums[i], nums[i]});
            currMinSum = min({temp, currMinSum + nums[i], nums[i]});
            ans = max({ans, currMaxSum, currMinSum});
            globalMin = min({globalMin, currMaxSum, currMinSum});
        }

        if (total - globalMin > ans and ans >= 0) ans = total - globalMin;
        return ans;
    }
};