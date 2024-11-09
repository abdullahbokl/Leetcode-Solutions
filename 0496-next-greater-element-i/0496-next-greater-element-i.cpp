class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;
        stack<int> st;
        unordered_map<int, int> mp;
        // predix >> the next greater element for each element in nums2
        for (int i = (int) nums2.size() - 1; i >= 0; i--) {
            while (!st.empty() && st.top() <= nums2[i]) {
                st.pop();
            }
            if (st.empty()) {
                mp[nums2[i]] = -1;
            } else {
                mp[nums2[i]] = st.top();
            }
            st.push(nums2[i]);
        }
        for (int i = 0; i < nums1.size(); i++) {
            ans.push_back(mp[nums1[i]]);
        }
        return ans;
    }
};