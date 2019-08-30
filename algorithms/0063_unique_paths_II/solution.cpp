class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        
        int n = obstacleGrid.size(), m = obstacleGrid[0].size();
        
        if (obstacleGrid[n-1][m-1] == 1) return 0;
        
        vector<vector<long long int>> paths;
        paths.resize(n);
        for (auto & vec : paths) vec.resize(m);
        
        for (int i = 0 ; i < obstacleGrid.size(); i++)
            for (int j = 0 ; j < obstacleGrid[i].size(); j++)
                if (obstacleGrid[i][j] == 1)
                    paths[i][j] = -1;
        
        for (int row = n-1; row >= 0; row--) {
            for (int col = m-1; col >= 0; col--) {
                if (paths[row][col] == -1) continue;
                if (row == n-1 && col == m-1) paths[row][col] = 1;
                else if (row == n-1) paths[row][col] = paths[row][col+1];
                else if (col == m-1) paths[row][col] = paths[row+1][col];
                else  {
                    
                    long long int down = paths[row+1][col] == -1 ? 0 : paths[row+1][col];
                    long long int right = paths[row][col+1] == -1 ? 0 : paths[row][col+1];
                    paths[row][col] = down + right;
                
                }
                    
            }
        }
        
        return paths[0][0] == -1 ? 0 : paths[0][0];  
    }
};