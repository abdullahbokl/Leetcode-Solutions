class Solution {
public:
    double average(vector<int>& salary) {
        int mx = INT_MIN, mn = INT_MAX;
        double total = 0;
        for (int num: salary) {
            total += num;
            mx = max(mx, num), mn = min(mn, num);
        }
        total -= mx + mn;
        total /= double (salary.size() - 2);
        return total;
    }
};