class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        queue<int> ins_positions;
        int z_count = 0;        
        for(int i = 0; i < nums.size(); i++) {
            ins_positions.push(i);
            if(nums[i] == 0) {
                z_count++;
            }
            else {
                int next = i;
                if (!ins_positions.empty()) {
                    next = ins_positions.front();
                    ins_positions.pop();
                }
                nums[next] = nums[i];
            }
        }
        
        for(int i = nums.size() - z_count; i < nums.size(); i++) {
            nums[i] = 0;
        }
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
        vector<int> nums = stringToIntegerVector(line);
        
        Solution().moveZeroes(nums);

        string out = integerVectorToString(nums);
        cout << out << endl;
    }
    return 0;
}