class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        vector<int> res(intervals.size(), -1);
        
        unordered_map<int, int> start_points;
        int max_start = intervals[0][0];
        for (int i = 0; i < intervals.size(); i++) {
            max_start = max(max_start, intervals[i][0]);
            start_points.insert(pair<int,int>(intervals[i][0], i));
        }
        
        for (int i = 0; i < intervals.size(); i++) {
            
            vector<int> & curr = intervals[i];
            if (curr[1] > max_start) continue;
            
            for (int end = curr[1]; end <= max_start; end++) {
                
                unordered_map<int,int>::iterator it = start_points.find(end);
                if(it == start_points.end()) continue;
                
                // first found is the minimum one
                res[i] = it->second;
                break;                
            }
            
        }
        
        return res;
    }
};