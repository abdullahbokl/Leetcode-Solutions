class Solution {
private:
    // sort the vector in descending order
    static void sortVec(vector<pair<int, char>> &freq) {
        sort(freq.begin(), freq.end(), greater<>());
    }

public:
    string longestDiverseString(int a, int b, int c) {

        vector<pair<int, char>> freq;
        freq.emplace_back(a, 'a');
        freq.emplace_back(b, 'b');
        freq.emplace_back(c, 'c');

        sortVec(freq);


        string ans = "";

        while (true) {
            for (int i = 0; i < 3; ++i) {
                int currentSize = (int) ans.size();

                if (freq[i].first > 0) {
                    if (currentSize >= 2 and ans[currentSize - 1] == ans[currentSize - 2] and
                        ans[currentSize - 2] == freq[i].second) {
                        continue;
                    }

                    ans += freq[i].second;
                    freq[i].first--;
                    sortVec(freq);
                    break;
                }
            }

            int currentSize = (int) ans.size();
            if (freq[0].first == 0) return ans;
            else if (freq[1].first == 0 and freq[2].first == 0 and currentSize >= 2 and
                     ans[currentSize - 1] == ans[currentSize - 2] and ans[currentSize - 2] == freq[0].second) {
                return ans;
            }
        }
    }
};
