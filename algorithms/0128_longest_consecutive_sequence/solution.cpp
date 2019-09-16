class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> found;
        for (int num : nums) found.insert(num);
        
        int max = 0;
        for (int num : nums) {
            if (found.find(num-1) != found.end()) continue;
            
            int seq = 1;
            int to_find = num+1;
            while(found.find(to_find) != found.end()) {
                seq++;
                to_find++;
            }
            
            if (seq > max) max = seq;
        }
        
        return max;
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
        
        int ret = Solution().longestConsecutive(nums);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}