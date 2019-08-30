class Solution {
public:
    bool is_palindrome(string &s) {
        int iters = s.length()/2;
        for (int i1 = 0, i2 = s.length()-1, i = 0; i < iters; i1++, i2--, i++) {
            if (s[i1] != s[i2]) return false;
        }
        return true;
    }
    
    string longestPalindrome(string s) {
        
        if (s.length() == 0) return "";
        
        int max_l = 1;
        string max_pali = string() + s[0];
        
        for (int i = 0 ; i < s.length(); i++) {            
            if (s.length() - i <= max_l) break;            
            string curr = string() + s[i];
            for (int j = i+1; j < s.length(); j++) {
                curr += s[j];
                if (curr.length() > max_l && is_palindrome(curr)) {
                    max_pali = curr;
                    max_l = curr.length();
                }
            }
        }
        return max_pali;
        
    }
};