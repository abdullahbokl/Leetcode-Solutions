class Solution {
public:
    int maxSubArray(vector<int> &nums) {
        int sum = 0, ans = INT_MIN;
        
        for (const int num: nums) {
            sum = max(num, sum + num);
            ans = max(ans, sum);
        }

        return ans;
    }
};