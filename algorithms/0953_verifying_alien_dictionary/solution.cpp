class Solution {
public:
    string substituteChars(const string &w, unordered_map<char,int> &subs) {
        string res = "";
        for(char c : w) {
            res += ('a' + subs[c]);
        }
        return res;
    }
    
    bool isAlienSorted(vector<string>& words, string order) {
        unordered_map<char, int> letters;
        for(int i = 0; i < order.length(); i++) letters[order[i]] = i;
        
        string w1, w2;
        for(int i = 0; i < words.size()-1; i++) {
            w1 = words[i];
            w2 = words[i+1];
            
            if (substituteChars(w1,letters) > substituteChars(w2,letters)) return false;
        }
        
        return true;
    }
};