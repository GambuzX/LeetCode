class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxsum = nums[0];
        int curr_sum = nums[0];
        
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] > curr_sum + nums[i]) {
                if (nums[i] > maxsum) maxsum = nums[i];
                curr_sum = nums[i];
            }
            else {
                curr_sum += nums[i];
                if (curr_sum > maxsum) {
                    maxsum = curr_sum;
                }
            }
        }
        
        return maxsum;
    }
};