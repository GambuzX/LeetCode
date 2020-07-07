class Solution {
public:
    bool isMatch(string s, string p) {
        return isMatch(s,p,0,0);
    }
    
    bool match(char c1, char c2) {
        return c1 == c2 || c2 == '.';
    }
    
    bool isMatch(string s, string p, int i1, int i2) {
        
        if (i2 >= p.length()) return i1 >= s.length();
        
        char pattern_c = p[i2];
        bool star = i2+1 < p.length() && p[i2+1] == '*';
        
        if(!star) {        
            if (i1 >= s.length()) return false;
            if(!match(s[i1], pattern_c)) return false;
            return isMatch(s, p, i1+1, i2+1);
        }
        
        // has star
        int right_i = i1;
        while(right_i < s.length() && match(s[right_i], pattern_c)) {
            right_i++;
        }
              
        for (int window = right_i-i1; window >= 0; window--) {
            if(isMatch(s, p, i1+window, i2+2)) return true;
        }
        
        return false;
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