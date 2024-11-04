class Solution {
public:
    string compressedString(string word) {
        string res;
        int n = word.size();
        int i = 0;
        while (i < n) {
            int j = i;
            while (j < n && word[j] == word[i] && j - i < 9) j++;
            res += to_string(j - i) + word[i];
            i = j;
        }
        return res;
    }
};
