class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int n = (int) nums.size(), i = 0, left = 0;
        long long sum = 0, currentLength;
        for (; i < n; i++) {
            sum += nums[i];
            currentLength = i - left + 1;
            if (currentLength * nums[i] - sum > k)  sum -= nums[left++];
        }
        
        return i - left;
    }
};