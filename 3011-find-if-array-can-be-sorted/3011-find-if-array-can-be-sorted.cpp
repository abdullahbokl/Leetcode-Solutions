class Solution {
private:
    long long countSetBits(long long n) {
        long long ans = 0;
        while (n) {
            n &= (n - 1);
            ++ans;
        }
        return ans;
    }

    vector<int> bits;

public:
    bool canSortArray(vector<int>& nums) {
        int sz = (int) nums.size();
        for (int i = 0; i < sz; ++i) {
            bits.emplace_back(countSetBits(nums[i]));
        }
        for (int i = 1; i < sz; ++i) {
            int j = i;
            while (j > 0 and nums[j] < nums[j - 1]) {
                if (bits[j] != bits[j - 1]) return false;
                swap(bits[j], bits[j-1]);
                swap(nums[j], nums[j-1]);
                j--;
            }
        }


        return true;
    }
};
