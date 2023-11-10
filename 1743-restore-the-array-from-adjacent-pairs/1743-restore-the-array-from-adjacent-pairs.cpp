class Solution {
public:
    vector<int> restoreArray(vector<vector<int>> &adjacentPairs) {
        unordered_map<int, vector<int>> mp;
        for (auto &i: adjacentPairs) {
            mp[i[0]].push_back(i[1]);
            mp[i[1]].push_back(i[0]);
        }

        vector<int> ans;
        for (auto &i: mp) {
            if (i.second.size() == 1) {
                ans.push_back(i.first);
                ans.push_back(i.second[0]);
                break;
            }
        }

        int sz = static_cast<int>(adjacentPairs.size());
        int ansSz = static_cast<int>(ans.size());
        int last, secondLast;
        while (ansSz <= sz) {
            last = ans.back();
            secondLast = ans[ansSz - 2];
            for (auto &i: mp[last]) {
                if (i != secondLast) {
                    ans.push_back(i);
                    break;
                }
            }
            ansSz++;
        }
        return ans;
    }
};
