class Solution {
public:
    bool isMatch(string s, string p) {
        unordered_map<string, bool> memo;
        return isMatch(memo,s,p,0,0);
    }
    
    bool match(char c1, char c2) {
        return c1 == c2 || c2 == '?';
    }
    
    string hash_str(string s, string p, int i1, int i2) {
        return s + "-" + p + "-" + to_string(i1) + "-" + to_string(i2);
    }
    
    bool isMatch(unordered_map<string, bool> &memo, string s, string p, int i1, int i2) {
        
        string strHash = hash_str(s,p,i1,i2);
        if(memo.find(strHash) != memo.end()) return memo.find(strHash)->second;
        
        bool res;
        if (i2 >= p.length()) {
            res = i1 >= s.length();
        }
        else if (i1 >= s.length() && p[i2] == '*') {
            res = true;
            for (int i = i2+1; i < p.length(); i++) {
                if (p[i] != '*') {
                    res = false;
                    break;
                }
            }
        }
        else if(p[i2] != '*') {  
            bool first_match = i1 < s.length() && match(s[i1], p[i2]);                  
            res = first_match && isMatch(memo,s,p,i1+1,i2+1);
        }
        else {
            res = isMatch(memo,s,p,i1,i2+1) || isMatch(memo,s,p,i1+1,i2);
        }
        
        memo.insert(make_pair(strHash, res));
        return res;
    }
};