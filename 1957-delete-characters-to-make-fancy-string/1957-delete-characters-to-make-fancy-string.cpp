class Solution {
public:
    string makeFancyString(string s) {
        string newString = "";
        for (int i = 0; i < min((int) s.size(), 2); ++i) {
            newString += s[i];
        }

        for (int i = 2; i < s.size(); ++i) {
            int newStringSize = newString.size();
            if (s[i] != newString[newStringSize - 1] || s[i] != newString[newStringSize - 2]) {
                newString += s[i];
            }
        }

        return newString;
    }
};