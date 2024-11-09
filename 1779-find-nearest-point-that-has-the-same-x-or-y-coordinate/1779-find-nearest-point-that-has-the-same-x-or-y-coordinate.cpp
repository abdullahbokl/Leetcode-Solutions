class Solution {
public:
    int nearestValidPoint(int x, int y, vector<vector<int>>& points) {
        int min = INT_MAX;
        int index = -1;
        for (int i = 0; i < points.size(); i++) {
            if (points[i][0] == x || points[i][1] == y) {
                int distance = abs(points[i][0] - x) + abs(points[i][1] - y);
                if (distance < min) {
                    min = distance;
                    index = i;
                }
            }
        }
        return index;
    }
};
