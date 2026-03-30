class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        long long target = k * threshold;
        long long sum = 0;
        int cnt = 0, size = arr.size();
        int left = 0, right = 0;

        while (right < k) sum += arr[right++];
        if (sum >= target)  cnt++;

        while (right < size) {
            sum += arr[right++];
            sum -= arr[left++];
            if (sum >= target)  cnt++;
        }

        return cnt;
    }
};