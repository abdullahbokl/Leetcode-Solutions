class Solution {
public:
    int trap(vector<int> &height) {
        int n = static_cast<int>(height.size()), ans = 0;
        vector<int> left(n), right(n);
        left[0] = height[0];
        right[n - 1] = height[n - 1];
        for (int i = 1; i < n; i++) {
            left[i] = left[i - 1] > height[i] ? left[i - 1] : height[i];
            right[n - i - 1] = right[n - i] > height[n - i - 1] ? right[n - i] : height[n - i - 1];
        }
        for (int i = 0; i < n; i++) ans += (left[i] > right[i] ? right[i] : left[i]) - height[i];
        return ans;
    }
};