class Solution {
public:
    bool checkIfExist(vector<int> &arr) {
        sort(arr.begin(), arr.end());
        int sz = (int) arr.size(), temp;
        for (int i = 0; i < sz; i++) {
            temp = arr[i] * 2;
            int idx = lower_bound(arr.begin(), arr.end(), temp) - arr.begin();
            if (idx < sz && arr[idx] == temp && idx != i) return true;
        }

        return false;
    }
};