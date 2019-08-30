class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> solution;
        
        unordered_map<int, int> seen;
        
        for(int i = 0; i < nums.size(); i++) {
            unordered_map<int,int>::iterator it = seen.find(target - nums.at(i));
            if (it == seen.end()) {
                seen.insert(pair<int,int>(nums.at(i), i));
            }
            else {
                solution.push_back(it->second + 1);
                solution.push_back(i + 1);
            }
        }        
        
        return solution;
    }
};