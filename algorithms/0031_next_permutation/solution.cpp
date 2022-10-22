class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int s = nums.size();        
        for (int pos = s-2; pos >= 0; pos--) {
            for (int i = s-1; i > pos; i--) {
                if (nums[i] > nums[pos]) {
                    int temp = nums[i];
                    nums[i] = nums[pos];
                    nums[pos] = temp;
                    sort(nums.begin()+pos+1, nums.end());
                    return;
                }
            }
        }
        
        reverse(nums.begin(), nums.end());
    }
};