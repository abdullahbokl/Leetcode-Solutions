class Solution {
private:
    bool isPossible(vector<int>& quantities, int mid, int n) {
        int total = 0;
        for (int quantity : quantities) {
            total += ceil((double)quantity / mid);
        }

        return total <= n;
    }


public:
    int minimizedMaximum(int n, vector<int>& quantities) {
        int left = 1, right = *max_element(quantities.begin(), quantities.end()), mid = 0;
        while (left < right) {
            mid = left + (right - left) / 2;
            if (isPossible(quantities, mid, n)) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }

        return right;
    }
};
