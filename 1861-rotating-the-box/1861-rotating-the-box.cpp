class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
        int m = box.size(), n = box[0].size(); // dimensions 
        vector<vector<char>> ans(n, vector<char>(m)); 
        
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
                ans[j][i] = box[m-1-i][j]; 
        
        for (int j = 0; j < m; ++j) {
            int k = 0; 
            for (int i = 0; i < n; ++i) {
                if (ans[i][j] == '#') {
                    ans[i][j] = '.';
                    ++k; 
                }
                if (i+1 == n || ans[i+1][j] == '*') {
                    while (k) {
                        ans[i+1-k][j] = '#'; 
                        --k; 
                    }
                }
            }
        }
        return ans; 
    }
};