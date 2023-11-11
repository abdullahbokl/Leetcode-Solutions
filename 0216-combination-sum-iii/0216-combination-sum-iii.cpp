class Solution {

public:
    vector<vector<int>> combinationSum3(int k, int n) {
        bt(k, n, {}, 1);
        return ans;
    }

private:
    vector<vector<int>> ans;

    void bt(int length, int sum, vector<int> &&temp, int start) {
        if (sum == 0 && length == 0) {
            ans.push_back(temp);
            return;
        }
        if (length == 0) return;
        for (int i = start; i <= 9; i++) {
            if (sum - i < 0) break;
            if (length - 1 < 0) break;
            temp.push_back(i);
            bt(length - 1, sum - i, std::move(temp), i + 1);
            temp.pop_back();
        }
    }
};