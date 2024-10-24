class Solution {
private:
    int arr[20004];
public:
    int deleteAndEarn(vector<int> &nums) {
        fill(arr, arr + 20004, 0);
        for (int &num: nums) arr[num] += num;

        arr[1] = max(arr[0], arr[1]);

        for (int i = 2; i < 20004; ++i) {
            arr[i] = max(arr[i] + arr[i-2], arr[i-1]);
        }

        return arr[20003];
    }
};