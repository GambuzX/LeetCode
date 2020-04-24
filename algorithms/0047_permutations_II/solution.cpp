class Solution {
public:
    
    void heapPermutations(vector<int> &nums, int n, set<vector<int>> & perms) {
        if (n == 1) {
            perms.insert(nums);
            return;
        }
        
        for (int i = 0; i < n; i++) {
            heapPermutations(nums, n-1, perms);
            
            if (n % 2 == 0) {
                int temp = nums[i];
                nums[i] = nums[n-1];
                nums[n-1] = temp;
            }
            else {
                int temp = nums[0];
                nums[0] = nums[n-1];
                nums[n-1] = temp;                
            }
        }
    }
    
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        set<vector<int>> perms;
        heapPermutations(nums, nums.size(), perms);
        return vector(perms.begin(), perms.end());
    }
};