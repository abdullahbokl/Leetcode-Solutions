class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>> &intervals) {

        sort(intervals.begin(), intervals.end());

        int end = intervals[0][1];

        int cnt = 0, sz = int(intervals.size());

        for (int i = 1; i < sz; ++i) {
            if (intervals[i][0] >= end) {
                end = intervals[i][1];
            } else {
                cnt++;
                end = min(end, intervals[i][1]);
            }
        }

        return cnt;
    }

};