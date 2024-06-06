
class Solution {
public:
    vector<int> runningSum(vector<int> &nums) {
        int sum = 0;
        for (auto &num: nums) {
            sum += num;
            num = sum;
        }

        return nums;
    }
};