class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        
        if (grid.size() == 0) return 0;
        
        int count = 0;
        int rows = grid.size();
        int cols = grid[0].size();
        for (int row = 0; row < rows; row++) {
            for (int col = 0; col < cols; col++) {
                
                if (grid[row][col] == '1') {
                    count++;
                    unmark_island(grid,row,col,rows,cols);
                }
            }
        }
        return count;
    }
    
    void unmark_island(vector<vector<char>>&grid, int row, int col, int rows, int cols) {
        if (row < 0 || col < 0 || row >= rows || col >= cols || grid[row][col] == '0')
            return;
        
        grid[row][col] = '0';
        
        unmark_island(grid, row+1, col,rows,cols);
        unmark_island(grid, row-1, col,rows,cols);
        unmark_island(grid, row, col+1,rows,cols);
        unmark_island(grid, row, col-1,rows,cols);
    }
};