class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int left = 0, right = 0;
        int size = int (nums.size());
        long long sum = 0;
        int ans = INT_MAX;

        while (right < size) {
            sum += nums[right];
            while (sum >= target) {
                ans = min(ans, right - left + 1);
                sum -= nums[left++];
            }

            right++;
        }

        return ans == INT_MAX ? 0 : ans;
    }
};