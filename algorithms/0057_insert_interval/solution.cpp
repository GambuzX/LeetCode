class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> res;
        
        bool merged = false;
        bool merging = false;
        for (auto & interval : intervals) {
            
            //overlapping
            if (!merged && !(newInterval[1] < interval[0] || newInterval[0] > interval[1])) {
                newInterval[0] = min(newInterval[0], interval[0]);
                newInterval[1] = max(newInterval[1], interval[1]);
                merging = true;
            }
            
            //does not overlap
            else {
                
                //add result of merging
                if (merging) {
                    res.push_back(newInterval);
                    merging = false;
                    merged = true;
                }
                
                //check if new interval is behind all intervals
                if (!merged && newInterval[1] < interval[0]) {
                    res.push_back(newInterval);
                    merged = true;
                }
                
                res.push_back(interval);
            }
        }
        
        //check if something was missing
        if (!merged) res.push_back(newInterval);
        
        return res;
    }
};