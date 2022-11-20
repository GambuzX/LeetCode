class Solution {
public:
    
    void helper(vector<int>& nums, vector<int> curr, int nexti, vector<vector<int>> & res) {
        if (nexti >= nums.size()) return;
        
        helper(nums, curr, nexti+1, res);
        
        vector<int> newsolution = curr;
        newsolution.push_back(nums[nexti]);
        res.push_back(newsolution);
        
        helper(nums, newsolution, nexti+1, res);
    }
    
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        res.push_back({});
        helper(nums, {}, 0, res);
        return res;
    }
};