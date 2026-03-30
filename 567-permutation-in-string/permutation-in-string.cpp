class Solution {
public:
    bool checkInclusion(string s1, string s2) {

        int size1 = s1.length();
        int size2 = s2.length();

        map<char, int> freq1;
        map<char, int> freq2;


        for (int i = 0; i < size1; i++) freq1[s1[i]]++;


        int l = 0, r = 0;

        while (r < size2) {
            char current = s2[r];

            freq2[current]++;

            if (freq1[current] == 0) {
                l = ++r;
                freq2.clear();
                continue;
            }

            while (freq2[current] > freq1[current]) {
                freq2[s2[l]]--;
                l++;
            }

            if (freq2[current] == freq1[current] and r - l + 1 >= size1) {
                return true;
            }

            r++;
        }
        return false;
    }
};