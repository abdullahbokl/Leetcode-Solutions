class Solution {

public:
    int maxProduct(vector<int> &nums) {

        int ans = nums[max_element(nums.begin(), nums.end()) - nums.begin()];
        int currMax = 1, currMin = 1;

        for (int num: nums) {
            if (num == 0) {
                currMax = currMin = 1;
                continue;
            }
            int temp = currMax * num;
            currMax = max({temp, currMin * num, num});
            currMin = min({temp, currMin * num, num});
            ans = max({currMax, currMin, ans});
        }

        return ans;
    }
};
