class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int s = nums.size(), i, j;        
        for (i = s-2; i >= 0; i--) {
            if (nums[i] < nums[i+1]) {
                break;   
            }
        }
        
        if (i < 0) {
            reverse(nums.begin(), nums.end());
            return;                
        }
        
        for (j = s-1; j > i; j--)
            if (nums[j] > nums[i]) break;
        
        swap(nums[i], nums[j]);
        reverse(nums.begin()+i+1, nums.end());
    }
};