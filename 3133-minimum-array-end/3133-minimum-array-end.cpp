class Solution {
public:
    long long minEnd(int n, int x) {
        long long ans = x;

        while (--n) {
            ans += 1;
            ans |= x;
        }

        return ans;
    }
};