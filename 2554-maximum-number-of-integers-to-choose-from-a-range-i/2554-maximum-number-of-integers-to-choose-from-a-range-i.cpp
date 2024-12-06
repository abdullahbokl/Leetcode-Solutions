class Solution {
public:
    int maxCount(vector<int> &banned, int n, int maxSum) {
        sort(banned.begin(), banned.end());
        int l = 0, r = 1, sum = 0, cnt = 0, sz = static_cast<int>(banned.size());
        while (r <= n and sum + r <= maxSum) {
            while (l < sz and banned[l] < r) l++;

            if (l < sz and banned[l] == r) {
                l++, r++;
                continue;
            }

            sum += r++;
            cnt++;
        }
        return cnt;
    }
};
