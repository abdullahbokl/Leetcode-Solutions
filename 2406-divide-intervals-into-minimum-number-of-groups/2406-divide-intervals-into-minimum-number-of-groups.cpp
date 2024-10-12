const int N = 10000005;
int pSum[N];

class Solution {
public:
    int minGroups(vector<vector<int>> &intervals) {
        memset(pSum, 0, sizeof(pSum));
        cout << 213131 << endl;
        int size = (int) intervals.size();
        for (int i = 0; i < size; ++i) {
            pSum[intervals[i][0]]++;
            pSum[intervals[i][1] + 1]--;
        }

        for (int i = 1; i < N; ++i) {
            pSum[i] += pSum[i - 1];
        }

        int mx = 0;
        for (int i = 0; i < N; ++i) {
            mx = max(mx, pSum[i]);
        }
        return mx;
    }
};