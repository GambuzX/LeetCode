class Solution {
public:
    struct g {
        int t;
        vector<int> comb;
    };
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        unordered_set<string> seen;
        
        queue<g> q;
        q.push(g{target, {}});
            
        while(!q.empty()) {
            g next = q.front();
            q.pop();
            
            for (int c : candidates) {
                int remaining = next.t - c;
                if (remaining < 0) continue;

                if (remaining == 0) {
                    vector<int> sol = next.comb;
                    sol.push_back(c);
                    
                    string key = "";
                    sort(sol.begin(), sol.end());
                    for(int i : sol) key += to_string(i);
                    if(seen.find(key) != seen.end()) continue;
                    
                    res.push_back(sol);
                    seen.insert(key);
                    continue;
                }
                
                g newg{remaining, next.comb};
                newg.comb.push_back(c);
                q.push(newg);                
            }            
            
        }
        
        return res;
    }
};