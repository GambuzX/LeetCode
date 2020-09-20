class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<unordered_set<char>> rows(9), cols(9), squares(9);
        for (int i = 0; i < 9; i++) {  // iterate rows
            for (int j = 0; j < 9; j++) {  // iterate cols
                char num = board[i][j];
                if (num == '.') continue;
                
                int curr_square = 3*(i/3) + j/3;
                if(rows[i].find(num) != rows[i].end()) return false;
                if(cols[j].find(num) != cols[j].end()) return false;
                if(squares[curr_square].find(num) != squares[curr_square].end()) return false;
                
                rows[i].insert(num);
                cols[j].insert(num);
                squares[curr_square].insert(num);
            }
        }
        return true;        
    }
};