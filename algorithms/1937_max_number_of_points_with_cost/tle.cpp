class Solution {
public:
    long long maxPoints(vector<vector<int>>& points) {
        const int m = points.size();
        const int n = points[0].size();
        
        vector<vector<long long>> best(m, vector<long long>(n, 0));
        
        for (int c = 0; c < n; c++)
            best[0][c] = points[0][c];
        
        for (int r = 1; r < m; r++) {
            for (int c = 0; c < n; c++) {
                long long currbest = 0;
                for (int c2 = 0; c2 < n; c2++) {
                    long long currscore = points[r][c] + best[r-1][c2] - abs(c-c2);
                    if (currscore > currbest) {
                        currbest = currscore;
                    }
                }
                best[r][c] = currbest;
            }
        }
        
        
        long long bestscore = 0;
        for (int c = 0; c < n; c++)
            bestscore = max(bestscore, best[m-1][c]);
        return bestscore;
    }
};