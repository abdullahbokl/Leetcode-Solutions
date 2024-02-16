class Solution {

private:

public:
    int findLeastNumOfUniqueInts(vector<int> &arr, int k) {
        // Count frequency of each element
        unordered_map<int, int> freq;
        for (int i: arr) freq[i]++;

        // Sort by value (frequency)
        vector<int> unique;
        for (auto &it: freq) unique.emplace_back(it.second);
        sort(unique.begin(), unique.end());

        // number of unique elements
        int ans = int(unique.size());

        // Remove elements with lowest frequency
        for (auto &i: unique) {
            if (k < i) break;
            k -= i, ans--;
        }

        return ans;
    }
};