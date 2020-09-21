class Solution {
public:
    set<string> genHelper(int n, unordered_map<int, set<string>>& dp) {
        if (dp.find(n) != dp.end()) {
            return dp.at(n);
        }        
        
        if (n == 1) {
            set<string> retSet;
            retSet.insert("()");
            dp.insert(make_pair(1, retSet));
            return retSet;
        }
        
        set<string> recursiveOptions = genHelper(n-1, dp);
        set<string> currOptions;
        for (const string & s : recursiveOptions) {
            currOptions.insert("()" + s);
            currOptions.insert("(" + s + ")");
            currOptions.insert(s + "()");
        }
        
        // aglutination
        for (int i = 2; i <= n/2; i++) {
            set<string> options1 = genHelper(i, dp);
            set<string> options2 = genHelper(n-i, dp);
            for (const string & s1 : options1) {
                for (const string & s2 : options2) {
                    currOptions.insert(s1 + s2);
                    currOptions.insert(s2 + s1);
                }
            }
            
        }
        
        dp.insert(make_pair(n, currOptions));
        return currOptions;
    }
    
    vector<string> generateParenthesis(int n) {
        unordered_map<int, set<string>> dp;
        set<string> options = genHelper(n, dp);
        return vector<string>(options.begin(), options.end());
    }
};