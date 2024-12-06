class Solution {
    // binary seach to check if the number is banned
    bool isBanned(vector<int> &banned, int n) {
        int l = 0, r = banned.size() - 1;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (banned[mid] == n) return true;
            if (banned[mid] < n) l = mid + 1;
            else r = mid - 1;
        }
        return false;
    }

public:
    int maxCount(vector<int> &banned, int n, int maxSum) {
        sort(banned.begin(), banned.end());
        int r = 1, sum = 0, cnt = 0;
        while (r <= n and sum + r <= maxSum) {
            if (isBanned(banned, r)) {
                r++;
                continue;
            }
            sum += r++;
            cnt++;
        }

        return cnt;
    }
};
