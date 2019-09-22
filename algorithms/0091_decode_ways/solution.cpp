class Solution {
public:
    int numDecodings(string s) {
        
        int single = 0;
        int mixed = 0;
        char prev = s[0];
        for (int i = 0; i < s.length(); i++) {
            char & c = s[i];
            
            if (i == 0 && c != '0') {
                single++;
            }            
            else if (c == '0') {
                if (!valid_comp(prev, c)) return 0;
                mixed = single;
                single = 0;
            }
            else {            
                int tmp = single;
                single += mixed;            
                mixed = valid_comp(prev, c) ? tmp : 0;                
            }
            
            prev = c;
        }
        
        return single + mixed;
    }
    
    bool valid_comp(char prev, char c) {
        return (prev == '1' && (c >= '0' && c <= '9')) || (prev == '2' && (c >= '0' && c <= '6'));
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

int main() {
    string line;
    while (getline(cin, line)) {
        string s = stringToString(line);
        
        int ret = Solution().numDecodings(s);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}