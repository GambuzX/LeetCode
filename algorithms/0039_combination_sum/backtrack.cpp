class Solution {
public:
    
    void backtrack(const vector<int> &candidates, int target, vector<int> curr, int curr_i, vector<vector<int>> &res) {
        
        for(int i = curr_i; i < candidates.size(); i++) {
            int c = candidates[i];
            int missing = target - c;
            if (missing < 0) continue;
            
            vector<int> sol = curr;
            sol.push_back(c);
            if (missing == 0) {
                res.push_back(sol);
                continue;
            }
            
            backtrack(candidates, missing, sol, i, res);
        }
        
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        sort(candidates.begin(), candidates.end());
        backtrack(candidates, target, {}, 0, res);
        return res;
    }
};