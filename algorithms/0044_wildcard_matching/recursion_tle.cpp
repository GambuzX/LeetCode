class Solution {
public:
    bool isMatch(string s, string p) {
        return isMatch(s,p,0,0);
    }
    
    bool match(char c1, char c2) {
        return c1 == c2 || c2 == '?';
    }
    
    bool isMatch(string s, string p, int i1, int i2) {
        
        if (i2 >= p.length()) return i1 >= s.length();
        
        char pattern_c = p[i2];
        
        if(pattern_c != '*') {        
            if (i1 >= s.length()) return false;
            if(!match(s[i1], pattern_c)) return false;
            return isMatch(s, p, i1+1, i2+1);
        }
        
        // is star              
        for (int window = s.length()-i1; window >= 0; window--) {
            if(isMatch(s, p, i1+window, i2+1)) return true;
        }
        
        return false;
    }
};