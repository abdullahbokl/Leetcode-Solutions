class Solution {
public:
    int subtractProductAndSum(int n) {
        short sum = 0;
        int product = 1;
        while (n) {
            int digit = n % 10;
            sum += digit;
            product *= digit;
            n /= 10;
        }
        return product - sum;
    }
};