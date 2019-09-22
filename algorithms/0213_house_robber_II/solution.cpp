class Solution {
public:
    int rob(vector<int>& nums) {
        
        if (nums.size() == 0) return 0;
        if (nums.size() == 1) return nums[0];
        
        vector<int> best(nums.size());
        return max(rob(nums, best, 0, nums.size()-2), rob(nums, best, 1, nums.size()-1));
    }
    
    int rob(vector<int>& nums, vector<int>& best, int left, int right) {
        
        best[0] = 0;        
        for (int i = left; i <= right; i++) {
            
            int offset = i-left+1;                
            if (i == left)
                best[offset] = nums[i];           
            else 
                best[offset] = max(nums[i] + best[offset-2], best[offset-1]); 
        }
        
        return best[right-left+1];
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
        
        int ret = Solution().rob(nums);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}