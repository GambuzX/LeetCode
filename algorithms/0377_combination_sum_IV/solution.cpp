class Solution {
private:
    int combinations;
    
public:
    int combinationSum4(vector<int>& nums, int target) {
        
        vector<unsigned long long> combs(target+1, 0);
        combs[0] = 1;
        
        for (int t = 1; t <= target; t++) {
            for (int i = 0; i < nums.size(); i++) {
                if (nums[i] <= t)
                    combs[t] += combs[t - nums[i]];
            }
        }
        
        return combs[target];
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
        vector<int> nums = stringToIntegerVector(line);
        getline(cin, line);
        int target = stringToInteger(line);
        
        int ret = Solution().combinationSum4(nums, target);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}