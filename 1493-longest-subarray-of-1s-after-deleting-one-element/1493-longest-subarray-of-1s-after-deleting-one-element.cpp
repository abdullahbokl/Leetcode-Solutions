class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size(), i = 0, left = 0, cnt = 0;
        
        for (; i < n; i++) {
            cnt += (nums[i] == 0);
            if (cnt > 1) cnt -= (nums[left++] == 0);
        }
        

        return i - left - 1;
    }
};