class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int max_cons = 0;
        int seq = 0;
        for (int num : nums) {
            if (num == 0) {
                max_cons = max(max_cons, seq);
                seq = 0;
            }
            else {
                seq++;
            }
        }
        max_cons = max(max_cons, seq);
        return max_cons;        
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
        vector<int> nums = stringToIntegerVector(line);
        
        int ret = Solution().findMaxConsecutiveOnes(nums);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}