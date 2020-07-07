class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        if (matrix.empty()) return res;
        
        int m = matrix.size(), n = matrix[0].size();
        int left, right, top, bot;
        left = 0;
        right = n-1;
        top = 0;
        bot = m-1;
        
        while(left <= right && top <= bot) {
            if (left == right) {
                for (int row = top; row <= bot; row++)
                    res.push_back(matrix[row][left]);
            }
            else if (top == bot) {
                for (int col = left; col <= right; col++)
                    res.push_back(matrix[top][col]);
            }
            else {            
                for (int col = left; col < right; col++)
                    res.push_back(matrix[top][col]);

                for (int row = top; row < bot; row++)
                    res.push_back(matrix[row][right]);

                for (int col = right; col > left; col--)
                    res.push_back(matrix[bot][col]);

                for (int row = bot; row > top; row--)
                    res.push_back(matrix[row][left]);
            }
            
            left++;
            right--;
            top++;
            bot--;
        }
        
        return res;
    }
};