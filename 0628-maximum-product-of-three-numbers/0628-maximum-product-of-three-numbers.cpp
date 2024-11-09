class Solution {
public:
    int maximumProduct(vector<int> &nums) {
        sort(nums.begin(), nums.end());
        int ans = 1, sz = (int) nums.size();
        for (int i = sz - 1; i >= sz - 3; --i) ans *= nums[i];
        ans = max(ans, nums[0] * nums[1] * nums[sz - 1]);
        return ans;
    }
};