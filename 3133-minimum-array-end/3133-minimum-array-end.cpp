class Solution {
public:
    long long minEnd(int n, int x) {
        int i = 0, j = 0;
        n--;
        long long ans = x;

        while (i < 64 and j < 64) {
            if (x & (1LL << i)) {
                i++;
                continue;
            }
            long long currentN = (n & (1LL << j));
            if (currentN) {
                ans = ans | (1LL << i);
            }
            j++;
            i++;
        }
        return ans;
    }
};