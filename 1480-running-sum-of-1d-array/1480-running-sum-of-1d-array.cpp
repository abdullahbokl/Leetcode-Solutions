class Solution {
public:
    vector<int> runningSum(vector<int> &nums) {
        int sum = 0;
        for_each(nums.begin(), nums.end(), [&](int &num) {
            sum += num;
            num = sum;
        });

        return nums;
    }
};