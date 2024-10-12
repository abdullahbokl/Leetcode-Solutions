class Solution {
private:
    inline void _concatBinaryNumbers(vector<int> &nums, vector<int> &bp) const {
        for (auto num: nums) {
            while (num) {
                bp.emplace_back(num & 1);
                num >>= 1;
            }
        }
    }

    inline int _reverseBinary(vector<int> &bp, int res) const {
        while (!bp.empty()) {
            res = res * 2 + bp.back();
            bp.pop_back();
        }
        return res;
    }

    inline int _calcConc(vector<int> &nums) {
        vector<int> bp = vector<int>();
        _concatBinaryNumbers(nums, bp);
        return _reverseBinary(bp, 0);
    }


public:
    int maxGoodNumber(vector<int> &nums) {
        int mx = 0;

        for (int i = 0; i < 6; ++i) {
            mx = max(mx, _calcConc(nums));
            next_permutation(nums.begin(), nums.end());
        }

        return mx;
    }
};
