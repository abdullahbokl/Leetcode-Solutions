class Solution {
public:
    int numSubarrayProductLessThanK(vector<int> &nums, int k) {
        int left = 0, product = 1, ans = 0, sz = (int) nums.size();
        for (int right = 0; right < sz; ++right) {
            product *= nums[right];

            while (product >= k and left <= right) {
                product /= nums[left++];
            }
            ans += right - left + 1;
        }
        return ans;
    }
};
