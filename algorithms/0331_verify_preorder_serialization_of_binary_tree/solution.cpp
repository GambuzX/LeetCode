class Solution {
public:
    bool isValidSerialization(string preorder) {
        
        if(preorder == "#") return true;
        
        int total_size = 1;
        for (auto & c : preorder)
            if (c == ',')
                total_size++;
        
        vector<int> child_count(total_size, 0);
        stack<int> parents;
        
        int start = 0;
        int end = 0;
        for (int i = 0; i < total_size; i++) {
            
            string curr;
            if (i == total_size-1) {
                curr = preorder.substr(start);
            }
            else {
                while(preorder[end] != ',') end++;
                curr = preorder.substr(start, end-start);
                start = end+1;
                end = start;
            }
                
            if (curr != "#") {
                parents.push(i);
                continue;
            }
            
            if(parents.empty()) return false;
            
            child_count[parents.top()]++;
            
            while(child_count[parents.top()] == 2) {
                parents.pop();
                if (parents.empty()) break;
                child_count[parents.top()]++;
            }
            
            if (i != total_size-1 && child_count[0] == 2) return false;
            
        }
        
        return child_count[0] == 2 && parents.empty();
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
        string preorder = stringToString(line);
        
        bool ret = Solution().isValidSerialization(preorder);

        string out = boolToString(ret);
        cout << out << endl;
    }
    return 0;
}