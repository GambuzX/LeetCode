class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) return false;
        
        vector<int> letters(26, 0);
        for (char & letter : s)
            letters.at(letter - 'a')++;
        
        for (char & letter : t) {
            if (letters.at(letter - 'a') > 0)
                letters.at(letter - 'a')--;
            else
                return false;
        }
        
        return true;
    }
};