class Solution {
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        
        unordered_map<int, int> sumAB;
        for(int a : A) for(int b : B) sumAB[a+b]++;
        
        int count = 0;
        for(int c : C) {
            for(int d : D) {
                int sumCD = c+d;
                unordered_map<int,int>::iterator it = sumAB.find(-sumCD);
                if (it == sumAB.end()) continue;
                count += it->second;                
            }
        }
        return count;
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

int main() {
    string line;
    while (getline(cin, line)) {
        vector<int> A = stringToIntegerVector(line);
        getline(cin, line);
        vector<int> B = stringToIntegerVector(line);
        getline(cin, line);
        vector<int> C = stringToIntegerVector(line);
        getline(cin, line);
        vector<int> D = stringToIntegerVector(line);
        
        int ret = Solution().fourSumCount(A, B, C, D);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}