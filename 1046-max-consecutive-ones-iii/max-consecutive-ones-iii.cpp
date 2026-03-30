class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int left = 0, right = 0;
        int cnt = 0, size = nums.size();
        int mx = 0;
        while (right < size) {
            if (nums[right]) {
                cnt++;
            }
            while (right - left + 1 - cnt > k) {
                cnt -= nums[left];
                left++;
            }

            mx = max(mx, right - left + 1);
            right++;
        }
        return mx;
    }
};