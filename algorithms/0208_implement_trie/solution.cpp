struct TrieNode {
  TrieNode * nodes[26];
    
    bool endNode;
    
    TrieNode() {
        endNode = false;
        for(int i = 0; i < 26; i++) nodes[i] = NULL;
    }
    
};

class Trie {
private:
    TrieNode * head;
    
public:
    /** Initialize your data structure here. */
    Trie() {
        head = new TrieNode();
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        TrieNode * iter = head;
        for(char & c: word) {
            if (iter->nodes[c-'a'] == NULL) iter->nodes[c-'a'] = new TrieNode();
            iter = iter->nodes[c-'a'];
        }
        iter->endNode = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        
        TrieNode * iter = head;
        for (char & c : word) {
            if (iter->nodes[c-'a'] == NULL) return false;
            iter = iter->nodes[c-'a'];
        }
        return iter->endNode;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        TrieNode * iter = head;
        for (char & c : prefix) {
            if (iter->nodes[c-'a'] == NULL) return false;
            iter = iter->nodes[c-'a'];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */