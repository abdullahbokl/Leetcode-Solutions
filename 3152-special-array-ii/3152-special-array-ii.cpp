class Solution {
public:
    vector<bool> isArraySpecial(vector<int> &nums, vector<vector<int>> &queries) {
        int sz = static_cast<int>(nums.size()), id = 0;
        vector<int> paritiesIds;
        paritiesIds.emplace_back(id);
        for (int i = 1; i < sz; i++) {
            if ((nums[i] & 1) == (nums[i - 1] & 1)) ++id;
            paritiesIds.emplace_back(id);
        }

        vector<bool> res;
        int l, r;
        for (auto &q: queries) {
            l = q[0], r = q[1];
            res.emplace_back(paritiesIds[l] == paritiesIds[r]);
        }
        return res;
    }
};
