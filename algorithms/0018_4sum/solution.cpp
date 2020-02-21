class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        
        vector<vector<int>> solutions;
        set<string> seen;
        
        if(nums.size() < 4) return solutions;
        
        unordered_map<int, vector<int>> vals;
        for(int i = 0; i < nums.size(); i++) {
            if(vals.find(nums[i]) == vals.end()) vals.insert(make_pair(nums[i], vector<int>()));
            vals.find(nums[i])->second.push_back(i);
        }
        
        for (int i = 0; i < nums.size()-3; i++) {
            if(nums[i] + 3 * nums[nums.size()-1] < target) continue;
            if(nums[i] * 4 > target) continue;
            
            for (int j = i+1; j < nums.size()-2; j++) {
                int firstTwoSum = nums[i] + nums[j];
                
                if(firstTwoSum + 2*nums[nums.size()-1] < target) continue;
                if(firstTwoSum + nums[j+1]*2 > target) continue;
                
                for (int k = j+1; k < nums.size()-1; k++) {
                    
                    int missing = target - nums[i] - nums[j] - nums[k];
                    if (missing < nums[k] || vals.find(missing) == vals.end()) continue;
                    
                    vector<int> & valid_iters = vals.find(missing)->second;
                    if (valid_iters[valid_iters.size()-1] <= k) continue;
                    
                    string sol = to_string(nums[i]) + "-" +
                                to_string(nums[j]) + "-" +
                                to_string(nums[k]) + "-" +
                                to_string(missing);

                    if (seen.find(sol) != seen.end()) continue;

                    seen.insert(sol);
                    solutions.push_back({nums[i], nums[j], nums[k], missing});
                }
            }
        }
        return solutions;
    }
};