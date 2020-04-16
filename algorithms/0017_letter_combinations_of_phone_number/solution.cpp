class Solution {
public:
    
    map<char, list<char>> digitToLetter = {
        {'2' , {'a', 'b', 'c'}},
        {'3' , {'d', 'e', 'f'}},
        {'4' , {'g', 'h', 'i'}},
        {'5' , {'j', 'k', 'l'}},
        {'6' , {'m', 'n', 'o'}},
        {'7' , {'p', 'q', 'r', 's'}},
        {'8' , {'t', 'u', 'v'}},
        {'9' , {'w', 'x', 'y', 'z'}}
    };
    
    vector<string> letterCombinations(string digits) {
        return getCombinations({}, digits, 0);
    }
    
    vector<string> getCombinations(const vector<string> & prev, string digits, int currI) {
        if (currI >= digits.length()) return prev;
        
        
        char currC = digits[currI++];
        list<char> options = digitToLetter.at(currC);
        vector<string> newCombs;
        for (const string & s : (prev.size() == 0 ? vector<string>(1,"") : prev)) {
            for (char c : options) {
                newCombs.push_back(s+c);
            }
        }
        return getCombinations(newCombs, digits, currI);        
    }
};