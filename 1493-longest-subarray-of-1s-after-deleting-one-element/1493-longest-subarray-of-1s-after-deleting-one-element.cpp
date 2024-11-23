class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size();
        vector<int> zeroIdx;
        
        zeroIdx.emplace_back(0);
        for (int i = 0; i < n; i++) {
            if (!nums[i])   zeroIdx.emplace_back(i + 1);
        }
        
        int sz = zeroIdx.size();
        if (sz == 1)    return n - 1;
        if (sz - 1 == n)    return 0;
        
        int ans = 0, temp = 0;
        for (int i = 2; i < sz; i++) {
            ans = max(ans, zeroIdx[i] - zeroIdx[i - 2] - 2);
        }
        
        ans = max(ans, n - zeroIdx[sz-2] - 1);

        return ans;
    }
};