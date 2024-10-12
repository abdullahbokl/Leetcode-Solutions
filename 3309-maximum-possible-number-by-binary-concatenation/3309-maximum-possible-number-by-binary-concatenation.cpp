class Solution {
private:
    // Helper to concatenate binary representations of numbers in the vector
    vector<int> concatBinaryNumbers(const vector<int> &nums) const {
        vector<int> bp;
        for (int num : nums) {
            vector<int> temp;
            while (num > 0) {
                temp.emplace_back(num & 1); // Extract the least significant bit
                num >>= 1; // Shift right
            }
            bp.insert(bp.end(), temp.rbegin(), temp.rend()); // Insert reversed binary
        }
        return bp;
    }

    // Helper to reverse the binary vector and convert it back to an integer
    int reverseBinary(const vector<int> &bp) const {
        int res = 0;
        for (int bit : bp) {
            res = (res << 1) | bit; // Shift left and add the next bit
        }
        return res;
    }

    // Calculate the "concatenated" binary value from the permutation
    int calcConc(const vector<int> &nums) const {
        auto bp = concatBinaryNumbers(nums); // Get binary concatenation
        return reverseBinary(bp); // Convert back to an integer
    }

public:
    // Function to get the maximum "good number"
    int maxGoodNumber(vector<int> &nums) {
        int mx = 0;
        for (int i = 0; i < 6; ++i) {
            mx = max(mx, calcConc(nums)); // Calculate and update max
            next_permutation(nums.begin(), nums.end()); // Get next permutation
        }
        return mx;
    }
};
