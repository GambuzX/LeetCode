bool overlaps(vector<int> int1, vector<int> int2) {    
    return !(int1[1] < int2[0] || int2[1] < int1[0]);    
}

bool compare_interval(vector<int> int1, vector<int> int2) {
    return int1[0] < int2[0];
}

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), compare_interval);            
        
        vector<vector<int>> result;
        int i = 0;
        while(i < intervals.size()) {
            vector<int> new_interval = intervals[i];
            
            int j = i+1;            
            
            while (j < intervals.size() && overlaps(new_interval, intervals[j])) {
                vector<int> & next = intervals[j];
                
                if (next[1] > new_interval[1])
                    new_interval[1] = next[1];
                
                j++;                
            }
            
            result.push_back(new_interval);
            i = j;
        }
        
        return result;
    }
};