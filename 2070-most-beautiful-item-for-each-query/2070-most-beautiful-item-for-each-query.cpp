class Solution {

private:
    int binarySearch(vector<pair<int, int>> &v, int target) {
        int l = 0, r = v.size() - 1, ans = -1;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (v[mid].first <= target) {
                if (ans == -1) ans = mid;
                else if (v[mid].second > v[ans].second) {
                    ans = mid;
                }
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        return ans;
    }


public:
    vector<int> maximumBeauty(vector<vector<int>> &items, vector<int> &queries) {

        map<int, int> mp;
        int n = (int) items.size();

        for (int i = 0; i < n; i++) {
            if (mp[items[i][0]] < items[i][1]) {
                mp[items[i][0]] = items[i][1];
            }
        }

        vector<pair<int, int>> v;
        for (auto &i: mp) v.emplace_back(i);

        for (int i = 1; i < v.size(); i++) {
            if (v[i].second < v[i - 1].second) {
                v[i].second = v[i - 1].second;
            }
        }

        vector<int> ans;
        for (int i = 0; i < queries.size(); i++) {
            int q = queries[i];
            int idx = binarySearch(v, q);

            if (idx == -1) {
                ans.push_back(0);
            } else {
                ans.push_back(v[idx].second);
            }
        }

        return ans;
    }
};
