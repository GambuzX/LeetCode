struct TriNode {
    TriNode * childs[27];
    
    bool endNode;
    
    TriNode() {
        for (int i = 0; i < 27; i++) childs[i] = NULL;
        endNode = false;
    };
};


class WordDictionary {
private:
    TriNode * head;
    
public:
    /** Initialize your data structure here. */
    WordDictionary() {
        head = new TriNode();
    }
    
    /** Adds a word into the data structure. */
    void addWord(string word) {
        TriNode * iter = head;
        for (auto & c : word) {
            if (iter->childs[c - 'a'] == NULL) {
                iter->childs[c - 'a'] = new TriNode();
            }
            
            iter = iter->childs[c - 'a'];
        }
        iter->endNode = true;
    }
    
    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word) {
        return search(word, 0, head);
    }
    
    bool search(const string & word, int index, TriNode * iter) {
        
        if (index == word.length()) return iter->endNode;
        
        if (word[index] == '.') {
            for (int i = 0; i < 26; i++) {
                if (iter->childs[i] != NULL && search(word, index+1, iter->childs[i])) 
                    return true;
            }
        }
        else if (iter->childs[word[index] - 'a'] != NULL)
            return search(word, index+1, iter->childs[word[index] - 'a']);
        
        return false;        
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */