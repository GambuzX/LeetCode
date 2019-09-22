class Solution {
public:
    bool canJump(vector<int>& nums) {
        
        int size = nums.size();
        vector<bool> canReach(size, false);
        
        int last_valid = size-1;
        for (int i = size-1; i >= 0; i--) {
            if (i + nums[i] >= size-1) {
                canReach[i] = true;
                last_valid = i;
                continue;
            }
            
            if (i + nums[i] < last_valid) continue;
            
            for (int step = nums[i]; step > 0; step--) {
                if (canReach[i + step]) {
                    canReach[i] = true;
                    last_valid = i;
                    break;
                }
            }
            
        }
        
        return canReach[0];
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

string boolToString(bool input) {
    return input ? "True" : "False";
}

int main() {
    string line;
    while (getline(cin, line)) {
        vector<int> nums = stringToIntegerVector(line);
        
        bool ret = Solution().canJump(nums);

        string out = boolToString(ret);
        cout << out << endl;
    }
    return 0;
}