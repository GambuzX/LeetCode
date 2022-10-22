class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();        
        int reachI = n-1;
        for(int i = n-2; i >= 0; i--) {
            int jump = i + nums[i];
            if (jump >= reachI) {
                reachI = i;
            }
        }
        
        return reachI == 0;
    }
};