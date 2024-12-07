class Solution {
public:
    int minimumSize(vector<int> &nums, int maxOperations) {
        int l = 1, r = 1e9;
        while (l < r) {
            int m = (l + r) / 2, cnt = 0;
            for (int i: nums) cnt += (i - 1) / m;
            if (cnt > maxOperations) l = m + 1;
            else r = m;
        }
        return l;
    }
};