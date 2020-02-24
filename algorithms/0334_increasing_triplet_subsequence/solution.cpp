class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int N = nums.size();
        
        if (N < 3) return false;
        
        vector<int> left(N);
        vector<int> right(N);
        
        left[1] = nums[0];
        for (int i = 2; i < N-1; i++) {
            left[i] = min(left[i-1], nums[i-1]);
        }
        
        right[N-2] = nums[N-1];
        for (int i = N-3; i > 0; i--) {
            right[i] = max(right[i+1], nums[i+1]);
        }
        
        for (int i = 1; i < N-1; i++)
            if (left[i] < nums[i] && nums[i] < right[i])
                return true;
        
        return false;        
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
        
        bool ret = Solution().increasingTriplet(nums);

        string out = boolToString(ret);
        cout << out << endl;
    }
    return 0;
}