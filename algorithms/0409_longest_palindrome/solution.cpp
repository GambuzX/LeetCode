class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char, int> charCount;
        for(char c : s) charCount[c]++;
        
        int foundOdd = 0;
        int maxLength = 0;
        for (const pair<char,int>& p : charCount) {
            if (p.second % 2 == 1) foundOdd = 1;
            
            maxLength += (p.second % 2 == 0) ? p.second : p.second - 1;
        }
        
        return maxLength + foundOdd;
    }
};