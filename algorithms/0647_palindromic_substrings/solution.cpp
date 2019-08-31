class Solution {
public:
    int countSubstrings(string s) {
        int count = 0;
        
        for (int i = 0; i < s.length(); i++) {
            for (int size = 1; size < s.length() - i + 1; size++) {                
                if (is_palindrome(s, i, i + size - 1)) count++;                
            }
        }
        
        return count;
    }
    
    bool is_palindrome(string &s, int i1, int i2) {
        while (i1 < i2) {
            if (s[i1] != s[i2]) return false;
            i1++;
            i2--;
        }
        return true;
    }
};