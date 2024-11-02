class Solution {
public:
    bool isCircularSentence(string sentence) {
        // divide the string into words
        vector<string> words;
        string word;
        for (char c: sentence) {
            if (c == ' ') words.emplace_back(word), word = "";
            else word += c;
        }
        words.emplace_back(word);

        int sz = words.size();
        for (int i = 0; i < sz; ++i) {
            if (words[i].back() != words[(i + 1) % sz].front()) return false;
        }

        return true;
    }
};