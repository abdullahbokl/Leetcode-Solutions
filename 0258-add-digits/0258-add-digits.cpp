class Solution {
public:
    int addDigits(int num) {
        int sum = num;
        while ((double) sum / 10.0 >= 1.0) {
            num = sum;
            sum = 0;
            while (num) {
                sum += num % 10;
                num /= 10;
            }
        }
        return sum;
    }
};