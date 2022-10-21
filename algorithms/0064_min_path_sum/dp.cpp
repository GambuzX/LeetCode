class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> res(m, vector<int>(n, INT_MAX));
        
        res[0][0] = grid[0][0];
        for (int c = 1; c < n; c++)
            res[0][c] = grid[0][c] + res[0][c-1];
        
        for (int r = 1; r < m; r++) {
            for (int c = 0; c < n; c++) {
                int left = c > 0 ? res[r][c-1] : INT_MAX/2;
                res[r][c] = grid[r][c] + min(res[r-1][c], left);
            }
        }
        
        return res[m-1][n-1];
    }
};