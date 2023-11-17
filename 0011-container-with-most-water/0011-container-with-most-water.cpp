class Solution {
public:
    int maxArea(vector<int> &height) {
        int l = 0, r = static_cast<int>(height.size()) - 1, ans = 0;
        while (l < r) {
            ans = max(ans, min(height[l], height[r]) * (r - l));
            height[l] < height[r] ? l++ : r--;
        }
        return ans;
    }
};