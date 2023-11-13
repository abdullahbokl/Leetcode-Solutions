class Solution {
public:
    int leastInterval(vector<char> &tasks, int n) {
        vector<int> freq(26);
        for (auto &i: tasks) freq[i - 'A']++;
        sort(freq.begin(), freq.end(), greater<>());

        int maxFreq = freq[0] - 1;
        int idleSlots = maxFreq * n;

        for (int i = 1; i < 26 && idleSlots > 0; i++) {
            idleSlots -= min(maxFreq, freq[i]);
        }

        idleSlots = max(0, idleSlots);

        return idleSlots + tasks.size();
    }
};