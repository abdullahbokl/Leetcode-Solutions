class Solution {
public:
    int maximumBeauty(vector<int> &nums, int k) {
        int l = 0, r = 0, sz = static_cast<int>(nums.size());

        sort(nums.begin(), nums.end());

        for (r = 0; r < sz; ++r) {
            if (nums[r] - nums[l] > 2 * k) ++l;
        }

        return r - l;
    }
};
