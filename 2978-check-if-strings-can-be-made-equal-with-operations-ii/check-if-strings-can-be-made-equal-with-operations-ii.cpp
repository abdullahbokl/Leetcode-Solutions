class Solution {
private:
    int charToInt(char ch) {
        return (ch - 'a');
    }
public:
    bool checkStrings(string s1, string s2) {

        vector<int> odd1(128);
        vector<int> odd2(128);
        vector<int> even1(128);
        vector<int> even2(128);

        int size1 = s1.length();
        int size2 = s2.length();

        for (int i = 0; i < size1; i++) {
            if (i & 1)
                odd1[charToInt(s1[i])]++;
            else
                even1[charToInt(s1[i])]++;
        }

        for (int i = 0; i < size2; i++) {
            if (i & 1)
                odd2[charToInt(s2[i])]++;
            else
                even2[charToInt(s2[i])]++;
        }

        // comapre
        bool flag = true;
        for (int i = 0; i < 128; i++) {
            if (odd1[i] != odd2[i] || even1[i] != even2[i]) {
                flag = false;
                break;
            }
        }

        return flag;
    }
};