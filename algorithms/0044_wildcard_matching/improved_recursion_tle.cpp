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
        if (i1 >= s.length() && p[i2] == '*') return isMatch(s,p,i1,i2+1);
        
        if(p[i2] != '*') {  
            bool first_match = i1 < s.length() && match(s[i1], p[i2]);                  
            return first_match && isMatch(s,p,i1+1,i2+1);
        }
        
        return isMatch(s,p,i1,i2+1) || isMatch(s,p,i1+1,i2);
    }
};