
class Solution {
public:
  vector<int> maxSlidingWindow(vector<int> &nums, int k) {

    deque<int> dq;
    vector<int> output;
    int n = nums.size();

    // prepare first window

    for (int i = 0; i < k; i++) {
      if (dq.empty()) {
        dq.push_back(i);
        continue;
      }
      while (!dq.empty() and nums[dq.back()] <= nums[i]) {
        dq.pop_back();
      }
      dq.push_back(i);
    }
    output.push_back(nums[dq.front()]);

    for (int i = k; i < n; i++) {
      if (dq.front() == i - k) {
        dq.pop_front();
      }
      while (!dq.empty() and nums[dq.back()] <= nums[i]) {
        dq.pop_back();
      }
      dq.push_back(i);
      output.push_back(nums[dq.front()]);
    }

    return output;
  }
};