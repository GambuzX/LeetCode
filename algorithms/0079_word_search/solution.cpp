class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        vector<vector<bool>> visited(board.size(), vector<bool>(board[0].size(), false));   
        
        for (int i = 0 ; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                if (board[i][j] == word[0] && findWord(board, i, j, word, 0, visited)) return true;
            }
        }
        
        return false;
    }
    
    bool findWord(vector<vector<char>> & board, int i , int j, string & word, int index, vector<vector<bool>> & visited) {
        if (index >= word.length()) return true;
        
        if (i < 0 || j < 0 || i >= board.size() || j >= board[0].size() || visited[i][j] || board[i][j] != word[index]) return false;
        
        visited[i][j] = true;
        
        if (findWord(board, i-1, j, word, index+1, visited)) return true;        
        if (findWord(board, i+1, j, word, index+1, visited)) return true;
        if (findWord(board, i, j-1, word, index+1, visited)) return true;  
        if (findWord(board, i, j+1, word, index+1, visited)) return true;
        
        visited[i][j] = false;
        
        return false;
    }
};