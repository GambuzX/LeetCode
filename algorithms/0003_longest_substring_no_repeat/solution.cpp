class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        int max_c = 0;
        int start = 0;
        
        unordered_map<char, int> found;
        for (int i = 0 ; i < s.length(); i++) {
            
            unordered_map<char,int>::iterator it = found.find(s[i]);
            
            // repeated
            if (it != found.end()) {
                if (it->second >= start)
                    start = it->second+1;
            }
            
            // store index
            found[s[i]] = i;
            
            max_c = max(max_c, i - start + 1);
        }
        
        return max_c;
    }
};