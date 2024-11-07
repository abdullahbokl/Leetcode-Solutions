class Solution {
public:
    bool rotateString(string s, string goal) {

        if (s.size() != goal.size()) return false;
        if (s == goal) return true;

        string s2 = s + s;
        return s2.find(goal) != string::npos;
    }
};