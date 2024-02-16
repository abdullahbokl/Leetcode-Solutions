class Solution {

private:
    static bool sortByValue(pair<int, int> &a, pair<int, int> &b) {
        return a.second < b.second;
    }

public:
    int findLeastNumOfUniqueInts(vector<int> &arr, int k) {
        // Count frequency of each element
        unordered_map<int, int> freq;
        for (int i: arr) freq[i]++;

        // Sort by value (frequency)
        vector<pair<int, int>> unique;
        for (auto &it: freq) unique.emplace_back(it);
        sort(unique.begin(), unique.end(), sortByValue);

        // number of unique elements
        int ans = int(unique.size());

        // Remove elements with lowest frequency
        for (auto &i: unique) {
            if (k < i.second) break;
            k -= i.second;
            ans--;
        }

        return ans;
    }
};