class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        
        vector<bool> valid(s.length()+1, false);
        valid[0] = true;
        
        for (int i = 0; i < s.length(); i++) {
            string subs = s.substr(i);
            
            if (!valid[i]) continue;
            
            for (string & word : wordDict) {
                
                if (word == subs.substr(0, word.length())) {
                    valid[i + word.length()] = true;
                }
                
            }
        }
        
        return valid[s.length()];
    }
};