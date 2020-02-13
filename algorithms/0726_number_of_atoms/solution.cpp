class Solution {
public:
    int i;
    string countOfAtoms(string formula) {
        i = 0;
        map<string, int> elements = getFormulaCounts(formula);        
        return buildResultFormula(elements);
    }
    
    map<string,int> getFormulaCounts(const string & formula) {
        map<string, int> elements;
        
        while(i < formula.length() && formula[i] != ')') {
            
            if (isupper(formula[i])) {
                
                string curr(1, formula[i++]);
                string count = "";
                
                while(islower(formula[i])) {
                    curr += formula[i++];
                }
                
                while(isdigit(formula[i])) {
                    count += formula[i++];
                }             
                
                elements[curr] += (count.length() != 0 ? stoi(count) : 1);
            }
            
            // parentheses
            else if (formula[i] == '(') {
                i++;
                map<string,int> recursive_res = getFormulaCounts(formula);
                for(auto & ele : recursive_res) 
                    elements[ele.first] += ele.second;
            }
        }
        
        i++;
        string count = "";                
        while(i < formula.length() && isdigit(formula[i])) {
            count += formula[i++];
        }
        
        int mult = count.length() != 0 ? stoi(count) : 1;
        for(auto & ele : elements) {
            ele.second *= mult;
        }
        
        return elements;
    }
    
    string buildResultFormula(map<string, int> & elements) {
        string res = "";
        
        for (auto & ele : elements) {
            res += ele.first;
            if (ele.second != 1)
                res += to_string(ele.second);
        }
        
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

int main() {
    string line;
    while (getline(cin, line)) {
        string formula = stringToString(line);
        
        string ret = Solution().countOfAtoms(formula);

        string out = (ret);
        cout << out << endl;
    }
    return 0;
}