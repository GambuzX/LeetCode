class Solution {
public:
    long long maxPoints(vector<vector<int>>& points) {
        const int m = points.size();
        const int n = points[0].size();
        
        vector<long long> best(n, 0);
        vector<long long> left(n, 0);
        vector<long long> right(n, 0);
        
        for (int c = 0; c < n; c++)
            best[c] = points[0][c];
        
        for (int r = 1; r < m; r++) {
            left[0] = best[0];
            for (int c = 1; c < n; c++)
                left[c] = max(left[c-1]-1, best[c]);
            
            right[n-1] = best[n-1];
            for (int c = n-2; c >= 0; c--)
                right[c] = max(right[c+1]-1, best[c]);            
            
            for (int c = 0; c < n; c++)
                best[c] = points[r][c] + max(left[c], right[c]);
        }
        
        
        long long bestscore = 0;
        for (int c = 0; c < n; c++)
            bestscore = max(bestscore, best[c]);
        return bestscore;
    }
};