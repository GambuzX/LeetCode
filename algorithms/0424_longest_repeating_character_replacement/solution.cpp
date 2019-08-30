class Solution {
public:
    int characterReplacement(string s, int k) {
        
        int count[26];
        memset(count, 0, sizeof(int) * 26);
        
        int start = 0;
        int max_count = 0;
        for (int i = 0 ; i < s.length(); i++) {
            count[s[i] - 'A']++;
            max_count = max(max_count, count[s[i] - 'A']);
            
            if (max_count + k < i - start + 1) {
                count[s[start] - 'A']--;
                start++;
            }
            
        }
        
        return s.length() - start;
        
    }
};