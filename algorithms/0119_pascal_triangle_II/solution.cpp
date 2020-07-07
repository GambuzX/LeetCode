class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> row(rowIndex+1, 1);
        
        for (int r = 2; r < rowIndex+1; r++) {
            int curr_size = r+1;
            int prev = row[0];
            for (int i = 1; i < curr_size-1; i++) {
                int newval = row[i] + prev;
                prev = row[i];
                row[i] = newval;
            }
        }
        
        return row;
    }
};

int stringToInteger(string input) {
    return stoi(input);
}

string integerVectorToString(vector<int> list, int length = -1) {
    if (length == -1) {
        length = list.size();
    }

    if (length == 0) {
        return "[]";
    }

    string result;
    for(int index = 0; index < length; index++) {
        int number = list[index];
        result += to_string(number) + ", ";
    }
    return "[" + result.substr(0, result.length() - 2) + "]";
}

int main() {
    string line;
    while (getline(cin, line)) {
        int rowIndex = stringToInteger(line);
        
        vector<int> ret = Solution().getRow(rowIndex);

        string out = integerVectorToString(ret);
        cout << out << endl;
    }
    return 0;
}