class Solution {
public:
    bool isPalindrome(string s) {
        string cleanstr = "";
        for (char c : s)
            if (isalnum(c))
                cleanstr += tolower(c);
        
        int N = cleanstr.length();
        stack<char> chars;
        for (int i = 0; i < N/2; i++)
            chars.push(cleanstr[i]);
        
        for (int i = (N % 2 == 0 ? N/2 : N/2+1); i < N; i++) {
            if (cleanstr[i] != chars.top()) return false;
            chars.pop();
        }
        return true;
    }
};