class Solution {
public:
    int maxProduct(vector<int>& nums) {
        
        int max_val = nums[0];
        int curr_max = nums[0];
        int curr_min = nums[0];
        
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] < 0)
                swap(curr_max, curr_min);
            
            curr_max = max(nums[i], nums[i] * curr_max);
            curr_min = min(nums[i], nums[i] * curr_min);
            
            max_val = max(max_val, curr_max);
        }
        
        return max_val;
    }
};