class Solution {
public:
    vector<int> smallestRange(vector<vector<int>> &nums) {
//        min heap
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<>> pq;
        vector<int> result;
        int left = INT_MAX, right = INT_MIN;
        for (int i = 0; i < nums.size(); ++i) {
            pq.emplace(nums[i][0], make_pair(i, 0));
            left = min(left, nums[i][0]);
            right = max(right, nums[i][0]);
        }
        result = {left, right};

        int listIdx, valueIdx;
        while (true) {
            listIdx = pq.top().second.first, valueIdx = pq.top().second.second;
            pq.pop();
            valueIdx++;
            if (valueIdx == nums[listIdx].size()) break;
            pq.emplace(nums[listIdx][valueIdx], make_pair(listIdx, valueIdx));
            left = max(left, pq.top().first);
            right = max(right, nums[listIdx][valueIdx]);
            if (right - left < result[1] - result[0]) {
                result = {left, right};
            }
        }
        return result;
    }
};
