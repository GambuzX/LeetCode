class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        unordered_map<int, int> l_index;
        for (int i = 0; i < nums.size(); i++)
            l_index[nums[i]] = i;
        
        vector<vector<int>> solution;
        for (int i = 0; i < nums.size(); i++) {
            if (i != 0 && nums[i] == nums[i-1]) continue;
            //count[nums[i]]--;
            
            for (int j = i+1; j < nums.size(); j++) {
                if (j != i+1 && nums[j] == nums[j-1]) continue;
                //count[nums[j]]--;
                
                int missing = 0 - nums[i] - nums[j];
                unordered_map<int,int>::iterator it = l_index.find(missing);
                if (it != l_index.end() && it->second > j) {
                    // add to solution set
                    solution.push_back({nums[i], nums[j], it->first});
                }
                
                //count[nums[j]]++;
            }
            //count[nums[i]]++;
        }
        
        return solution;
    }
};