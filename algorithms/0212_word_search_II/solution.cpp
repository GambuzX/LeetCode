struct TriNode {
    TriNode * nodes[26];
    bool endNode;
    int indexInVector;
    TriNode() { 
        endNode = false;
        for (int i = 0 ; i < 26; i++)
            nodes[i] = NULL;
    }
};


class Solution {
private:
    vector<bool> foundWords;
    
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        TriNode * root = new TriNode();
        vector<vector<bool>> visited(board.size(), vector<bool>(board[0].size(), false));
            
        for (int i = 0; i < words.size(); i++) addWord(root, words[i], i);          
        
        foundWords = vector<bool>(words.size(), false);
        
        for (int i = 0 ; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                findWords(board, i, j, root, visited);
            }
        }
        
        vector<string> res;
        for (int i = 0; i < foundWords.size(); i++)
            if (foundWords[i])
                res.push_back(words[i]);
        return res;
    }
    
    void addWord(TriNode * node, string & word, int indexInVector) {
        for (char c : word) {
            int offset = c - 'a';
            if (node->nodes[offset] == NULL)
                node->nodes[offset] = new TriNode();
            
            node = node->nodes[offset];
        }
        node->endNode = true;
        node->indexInVector = indexInVector;
    }
    
    void findWords(vector<vector<char>> & board, int i , int j, TriNode * node, vector<vector<bool>> & visited) {
        if (node == NULL || i < 0 || j < 0 || i >= board.size() || j >= board[0].size() || visited[i][j]) return;
        
        int offset = board[i][j] - 'a';
        TriNode * next = node->nodes[offset];
        if (next != NULL && next->endNode) foundWords[next->indexInVector] = true;
        
        visited[i][j] = true;
        
        findWords(board, i-1, j, next, visited);
        findWords(board, i+1, j, next, visited);
        findWords(board, i, j-1, next, visited);
        findWords(board, i, j+1, next, visited);
        
        visited[i][j] = false;
        
    }
};