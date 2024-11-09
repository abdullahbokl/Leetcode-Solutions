class Solution {
public:
    int numSubarrayProductLessThanK(vector<int> &nums, int k) {
        int currentScore = 0, totalScore = 0, ans = 1, sz = (int) nums.size(), left = 0;

        for (int i = 0; i < sz; ++i) {
            int temp = ans * nums[i];
            if (temp < k) {
                ans *= nums[i];
                currentScore++;

                if (i == sz - 1) {
                    totalScore += currentScore * (currentScore + 1) / 2;
                }
                continue;
            }

            if (left <= i) {
                totalScore += currentScore;
                ans /= nums[left];
                currentScore--;
                left++;
                i--;
            }
            if (currentScore < 0) currentScore = 0;
            if (ans == 0) ans = 1;
        }

        return totalScore;
    }
};
