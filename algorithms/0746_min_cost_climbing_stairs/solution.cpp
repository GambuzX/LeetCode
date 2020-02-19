class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n_steps = cost.size();
        vector<int> climb_cost(n_steps+1);
        
        climb_cost[n_steps] = 0;
        climb_cost[n_steps-1] = cost[n_steps-1];
        for (int s = n_steps-2; s >= 0; s--) {
            climb_cost[s] = cost[s] + min(climb_cost[s+1], climb_cost[s+2]);
        }
        
        return min(climb_cost[0], climb_cost[1]);
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
        vector<int> cost = stringToIntegerVector(line);
        
        int ret = Solution().minCostClimbingStairs(cost);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
