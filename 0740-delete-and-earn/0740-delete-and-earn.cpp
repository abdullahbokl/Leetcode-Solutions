class Solution {
private:
public:
    int deleteAndEarn(vector<int> &nums) {
    const int sz = 10001;
        int arr[sz] = {0};

        for (int &num: nums) arr[num] += num;

        int prev1 = 0, prev2 = 0, maxVal;

        for (int &num: arr) {
            maxVal = max(num + prev1, prev2);
            prev1 = prev2;
            prev2 = maxVal;
        }

        return maxVal;
    }
};