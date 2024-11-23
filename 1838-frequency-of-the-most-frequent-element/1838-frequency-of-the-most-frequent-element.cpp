class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int n = (int) nums.size(), ans = 0, currentLength = 0, left = 0;
        long long sum = 0;
        for (int i = 0; i < n; i++) {
            currentLength = i - left + 1;
            sum += nums[i];
            while ((long long) currentLength * nums[i] - sum > k) 
                sum -= nums[left++], currentLength = i - left + 1;
            
            ans = max(ans, currentLength);
        }
        
        return ans;
    }
};