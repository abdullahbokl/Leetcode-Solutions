class Solution {

public:
    vector<int> getMaximumXor(vector<int> &nums, int maximumBit) {
        int n = (int) nums.size(), target = (1 << maximumBit) - 1, prefix = nums[0];
        vector<int> ans;
        ans.emplace_back(prefix ^ target);
        for (int i = 1; i < n; ++i) {
            prefix ^= nums[i];
            ans.emplace_back(prefix ^ target);
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};