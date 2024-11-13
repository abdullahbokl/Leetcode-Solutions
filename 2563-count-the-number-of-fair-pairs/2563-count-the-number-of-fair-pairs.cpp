class Solution {
private:
    long long countLess(const vector<int> &nums, int sum, int sz) {
        long res = 0;
        for (int i = 0, j = sz - 1; i < j; ++i) {
            while (i < j && nums[i] + nums[j] > sum)
                --j;
            res += j - i;
        }
        return res;
    }

public:
    long long countFairPairs(vector<int> &nums, int lower, int upper) {
        int sz = (int) nums.size();
        sort(nums.begin(), nums.end());
        // what I did after sorting is: (number of pairs sum less than equal to upper - number of pairs sum less than lower)
        return countLess(nums, upper, sz) - countLess(nums, lower - 1, sz);
    }
};