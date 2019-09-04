class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        std::sort(intervals.begin(), intervals.end(), [](auto &a, auto &b) {
            return a[1] < b[1];
        });
        
        int prev = INT_MIN;
        int count = 0;
        for (auto & interval : intervals) {
            if (interval[0] >= prev)
                prev = interval[1];
            else
                count++;
        }
        return count;
    }
};