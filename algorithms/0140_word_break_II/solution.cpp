class Solution {
private:
    vector<string> solutions;
public:
    string rtrim(const string &s)
    {
        size_t end = s.find_last_not_of(" ");
        return (end == string::npos) ? "" : s.substr(0, end + 1);
    }
    
    void helper(string s, int left, string curr, vector<string>& wordDict) {
        if (left == s.length()) {
            solutions.push_back(rtrim(curr));
            return;
        }
        
        for (const string &word : wordDict) {
            int l = word.length();
            if (s.substr(left, l) == word) {
                helper(s, left+l, curr + word + " ", wordDict);
            }
        }
    }
    
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        solutions.clear();
        helper(s, 0, "", wordDict);
        return solutions;
    }
};