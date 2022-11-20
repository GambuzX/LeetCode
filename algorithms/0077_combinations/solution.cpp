class Solution {
public:
    
    void helper(vector<int> &nums, int k, vector<int> curr, int curri, vector<vector<int>> &res) {
        if (curr.size() == k) {
            res.push_back(curr);
            return;
        }
        if (curri >= nums.size() || curr.size() > k) return;
        
        
        for (int i = curri; i < nums.size(); i++) {
            curr.push_back(nums[i]);
            helper(nums, k, curr, i+1, res);
            curr.pop_back();
        }   
                
    }
    
    vector<vector<int>> combine(int n, int k) {
        vector<int> nums;
        for (int i = 1; i <= n; i++) nums.push_back(i);
        
        vector<vector<int>> res;
        helper(nums, k, {}, 0, res);
        return res;
    }
};