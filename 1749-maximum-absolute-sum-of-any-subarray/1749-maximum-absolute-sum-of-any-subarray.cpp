class Solution {
public:
    int maxAbsoluteSum(vector<int> &nums) {

        int sz = (int) nums.size(), currentMax = 0, currentMin = 0, ans = INT_MIN;

        for (int i = 0; i < sz; ++i) {
            currentMax = max(nums[i], currentMax + nums[i]);
            currentMin = min(nums[i], currentMin + nums[i]);
            ans = max({ans, currentMax, abs(currentMin)});
        }

        return ans;
    }
};