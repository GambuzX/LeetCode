class Solution {
public:
    int longestOnes(vector<int>& A, int K) {
        int zeroCount = 0, start = 0, res = 0;
        
        for (int end = 0; end < A.size(); end++) {
            if (A[end] == 0) zeroCount++;
            
            while(zeroCount > K) {
                if (A[start++] == 0) zeroCount--;
            }
            res = max(res, end - start + 1);
        }
        
        return res;
    }
    
};

void trimLeftTrailingSpaces(string &input) {
    input.erase(input.begin(), find_if(input.begin(), input.end(), [](int ch) {
        return !isspace(ch);
    }));
}

void trimRightTrailingSpaces(string &input) {
    input.erase(find_if(input.rbegin(), input.rend(), [](int ch) {
        return !isspace(ch);
    }).base(), input.end());
}

vector<int> stringToIntegerVector(string input) {
    vector<int> output;
    trimLeftTrailingSpaces(input);
    trimRightTrailingSpaces(input);
    input = input.substr(1, input.length() - 2);
    stringstream ss;
    ss.str(input);
    string item;
    char delim = ',';
    while (getline(ss, item, delim)) {
        output.push_back(stoi(item));
    }
    return output;
}

int stringToInteger(string input) {
    return stoi(input);
}

int main() {
    string line;
    while (getline(cin, line)) {
        vector<int> A = stringToIntegerVector(line);
        getline(cin, line);
        int K = stringToInteger(line);
        
        int ret = Solution().longestOnes(A, K);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}