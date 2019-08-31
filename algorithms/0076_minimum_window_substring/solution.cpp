class Solution {
public:
    string minWindow(string s, string t) {
        vector<int> count(128, 0);
        unordered_set<char> found;
        
        for (char c : t) {
            count[c]++;
            found.insert(c);
        }
        
        string res = "";        
        int missing = t.length();
        int start = 0;
        for (int i = 0; i < s.size(); i++) {
            
            if (--count[s[i]] >= 0) missing--;
            
            while (missing == 0) {
                // contract
                while(start <= i) {
                    if (found.find(s[start]) != found.end()) break;
                    start++;                    
                }
                
                // update min substring
                if (res == "" || res.length() > i - start + 1) {
                    res = s.substr(start, i - start + 1);
                }
                              
                if (++count[s[start++]] > 0) missing++;                
            }
        }
        return res;
    }
};