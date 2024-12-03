class Solution {
public:
    vector<int> resultsArray(vector<int> &nums, int k) {
        if (k == 1) return nums;
        vector<int> ans;
        int sz = static_cast<int>(nums.size());

        int cnt = 1, left = 1, right = k - 1;

        while (right < sz and left <= right) {
            if (nums[left] == nums[left - 1] + 1) cnt++;
            else cnt = 1;

            if (left == right) {
                if (cnt >= k) ans.emplace_back(nums[left]);
                else ans.emplace_back(-1);
                right++;
            }
            left++;
        }
        return ans;
    }
};
