class Solution {
public:
    
    void swap(vector<vector<int>>& matrix, int i1, int j1, int i2, int j2) {
        int temp = matrix[i1][j1];
        matrix[i1][j1] = matrix[i2][j2];
        matrix[i2][j2] = temp;
    }
    
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int layers = n/2;
        for (int i = 0; i < layers; i++) {
            int left=i, right=n-i-1, top=i, bot=n-i-1;
            
            // right side downwards
            for (int row = top; row < bot; row++)
                swap(matrix, top, row, row, right);
            
            // bottom side leftwards
            for (int col = right; col > left; col--)
                swap(matrix, top, n-col-1, bot, col);
            
            // left side upwards
            for (int row = bot; row > top; row--)
                swap(matrix, top, n-row-1, row, left);
        }
    }
};