class Solution {
public:
    vector<int> selfDividingNumbers(int left, int right) {
        vector<int> nums;
        for(int i = left; i <= right; i++) {
            if(isSelfDividing(i)) 
                nums.push_back(i);
        }
        return nums;
    }
    
    bool isSelfDividing(int orig) {
        int num = orig;
        int curr = num % 10;
        while(num != 0) {
            if (curr == 0 || orig % curr != 0) return false;
            
            num = num / 10;
            curr = num % 10;
        }
        
        return orig != 0;
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
        int left = stringToInteger(line);
        getline(cin, line);
        int right = stringToInteger(line);
        
        vector<int> ret = Solution().selfDividingNumbers(left, right);

        string out = integerVectorToString(ret);
        cout << out << endl;
    }
    return 0;
}