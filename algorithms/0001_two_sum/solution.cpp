class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> indices;
        unordered_map<int,int> count;
        for (int i = 0; i < nums.size(); i++) {
            count[nums[i]] = i;
        }
        
        for (int i = 0; i < nums.size(); i++) {
            int curr = nums[i];
            if (count.find(target-curr) != count.end() && count.find(target-curr)->second != i)
                return vector<int>{i, count[target-curr]};
        }
        
        
        
        return indices;
    }
};