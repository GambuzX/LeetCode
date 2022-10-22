class Solution {
public:
    
    void backtrack(const vector<int> &candidates, int target, vector<int> &currComb, int curr_i, vector<vector<int>> &res) {
        
        for(int i = curr_i; i < candidates.size(); i++) {
            
            if (i > curr_i && candidates[i] == candidates[i-1]) continue;
            
            int c = candidates[i];
            int missing = target - c;
            if (missing < 0) continue;
            
            currComb.push_back(c);
            if (missing == 0) {
                res.push_back(currComb);
            }
            else {                
                backtrack(candidates, missing, currComb, i+1, res);
            }
            currComb.pop_back();
        }
        
    }
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        sort(candidates.begin(), candidates.end());
        vector<int> currComb;
        backtrack(candidates, target, currComb, 0, res);
        return res;
    }
};