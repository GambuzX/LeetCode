class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> paths;
        paths.resize(n);
        for (auto & vec : paths) vec.resize(m);
        
        paths[n-1][m-1] = 1;
        
        for (int row = n-1; row >= 0; row--) {
            for (int col = m-1; col >= 0; col--) {
                if (row==n-1 || col==m-1) paths[row][col] = 1;
                else paths[row][col] = paths[row+1][col] + paths[row][col+1];
            }
        }
        
        return paths[0][0];        
    }
};