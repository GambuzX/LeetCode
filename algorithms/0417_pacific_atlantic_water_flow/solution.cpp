class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& matrix) {
        
        if (matrix.size() == 0) return vector<vector<int>>();
        
        vector<vector<bool>> pacific(matrix.size(), vector<bool>(matrix[0].size(), false));
        vector<vector<bool>> atlantic(matrix.size(), vector<bool>(matrix[0].size(), false));
        
        for (int row = 0; row < matrix.size(); row++) {
            mark_valid(matrix, pacific, row, 0);
            mark_valid(matrix, atlantic, row, matrix[0].size()-1);
        }
        for (int col = 0; col < matrix[0].size(); col++) {
            mark_valid(matrix, pacific, 0, col);
            mark_valid(matrix, atlantic, matrix.size()-1, col);
        }
        
        vector<vector<int>> res;
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[i].size(); j++) {
                if (pacific[i][j] && atlantic[i][j]) res.push_back({i,j});
            }
        }
        
        return res;        
    }
    
    void mark_valid(vector<vector<int>> & matrix, vector<vector<bool>> & helper, int row, int col) {
        if (row < 0 || col < 0 || row >= matrix.size() || col >= matrix[0].size() || helper[row][col]) return;
        
        helper[row][col] = true;
        
        if (row > 0 && matrix[row][col] <= matrix[row-1][col]) 
            mark_valid(matrix, helper, row-1, col);        
        
        if (row < matrix.size()-1 && matrix[row][col] <= matrix[row+1][col])
            mark_valid(matrix, helper, row+1, col);  
        
        if (col > 0 && matrix[row][col] <= matrix[row][col-1]) 
            mark_valid(matrix, helper, row, col-1);   
        
        if (col < matrix[0].size()-1 && matrix[row][col] <= matrix[row][col+1])
            mark_valid(matrix, helper, row, col+1);  
    }
};