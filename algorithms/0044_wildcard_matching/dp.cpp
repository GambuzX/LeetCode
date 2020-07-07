class Solution {
public:
    bool isMatch(string s, string p) {
        vector<vector<char>> memo(s.length()+1, vector<char>(p.length()+1, '?'));
        return isMatch(memo,s,p,0,0);
    }
    
    bool match(char c1, char c2) {
        return c1 == c2 || c2 == '?';
    }
    
    bool isMatch(vector<vector<char>> &memo, string s, string p, int i1, int i2) {
        
        if (memo[i1][i2] != '?') return memo[i1][i2] == 'y';
        
        bool res;
        if (i2 == p.length()) {
            res = i1 == s.length();
        }
        else if(p[i2] != '*') {  
            bool first_match = i1 < s.length() && match(s[i1], p[i2]);                  
            res = first_match && isMatch(memo,s,p,i1+1,i2+1);
        }
        else {
            res = isMatch(memo,s,p,i1,i2+1) || (i1 < s.length() && isMatch(memo,s,p,i1+1,i2));
        }
        
        memo[i1][i2] = res ? 'y' : 'n';
        return res;
    }
};

string stringToString(string input) {
    assert(input.length() >= 2);
    string result;
    for (int i = 1; i < input.length() -1; i++) {
        char currentChar = input[i];
        if (input[i] == '\\') {
            char nextChar = input[i+1];
            switch (nextChar) {
                case '\"': result.push_back('\"'); break;
                case '/' : result.push_back('/'); break;
                case '\\': result.push_back('\\'); break;
                case 'b' : result.push_back('\b'); break;
                case 'f' : result.push_back('\f'); break;
                case 'r' : result.push_back('\r'); break;
                case 'n' : result.push_back('\n'); break;
                case 't' : result.push_back('\t'); break;
                default: break;
            }
            i++;
        } else {
          result.push_back(currentChar);
        }
    }
    return result;
}

string boolToString(bool input) {
    return input ? "True" : "False";
}

int main() {
    string line;
    while (getline(cin, line)) {
        string s = stringToString(line);
        getline(cin, line);
        string p = stringToString(line);
        
        bool ret = Solution().isMatch(s, p);

        string out = boolToString(ret);
        cout << out << endl;
    }
    return 0;
}