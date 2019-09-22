class Solution {
public:
    int jump(vector<int>& nums) {
        
        int jumps = 0;
        int reach = 0;
        int step = 0;
        
        for (int i = 0; i < nums.size(); i++) {
            
            if (i > reach) return -1;
            
            if (i == nums.size()-1) break;
            
            reach = max(reach, i + nums[i]);
            
            if (step == 0) {
                jumps++;
                step = reach - i;
            }
            step--;
            
        }
        
        return jumps;
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
        
        int ret = Solution().jump(nums);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}