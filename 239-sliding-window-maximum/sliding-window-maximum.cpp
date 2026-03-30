class Solution {
public:
  vector<int> maxSlidingWindow(vector<int> &nums, int k) {
    deque<int> dq;
    vector<int> output;
    int n = nums.size();

    for (int i = 0; i < n; i++) {
      // 1. Remove indices that fell out of the window
      while (!dq.empty() && dq.front() <= i - k) {
        dq.pop_front();
      }
      // 2. Remove smaller elements from the back (maintain decreasing order)
      while (!dq.empty() && nums[dq.back()] <= nums[i]) {
        dq.pop_back();
      }
      dq.push_back(i);
      // 3. Once the first window is fully formed, record the max
      if (i >= k - 1) {
        output.push_back(nums[dq.front()]);
      }
    }
    return output;
  }
};