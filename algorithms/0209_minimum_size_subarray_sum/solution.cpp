class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int sol = INT_MAX;
        int l = 0;
        int currSum = 0;
        for(int r = 0; r < nums.size(); r++) {
            if (currSum < target) {
                currSum += nums[r];
            
                if (currSum >= target) {
                    sol = min(sol, r - l + 1);
                }
            }
            
            while(currSum >= target) {
                sol = min(sol, r - l + 1);
                currSum -= nums[l];
                l++;
            }
        }
        return sol == INT_MAX ? 0 : sol;
    }
};