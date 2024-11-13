class Solution {
public:
    long long countFairPairs(vector<int> &nums, int lower, int upper) {
        int n = (int) nums.size();
        sort(nums.begin(), nums.end());
        long long ans = 0;
        int lowerBound = n;
        int upperBound = n - 1;
        for (int i = 0; i < n; i++) {
            // find the first value less than lower
            while (lowerBound > 0 && nums[i] + nums[lowerBound - 1] >= lower) lowerBound--;
            // find the first value less than or equal to upper
            while (upperBound >= 0 && nums[i] + nums[upperBound] > upper) upperBound--;
            // the range [lowerBound, upperBound] is the range of valid pairs
            int add = upperBound - lowerBound + 1;
            // if the current value is in the range, we need to subtract 1 to avoid counting the pair (i, i) twice
            if (i <= upperBound && i >= lowerBound) add--;
            ans += add;
        }
        // divide by 2 to avoid counting each pair twice such as (i, j) and (j, i)
        return ans / 2;
    }
};