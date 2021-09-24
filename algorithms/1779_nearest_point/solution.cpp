class Solution {
public:
    int nearestValidPoint(int x, int y, vector<vector<int>>& points) {
        int sol = -1;
        int minDist = INT_MAX;
        for(int i = 0; i < points.size(); i++) {
            const vector<int> &p = points[i];
            if (!(p[0] == x || p[1] == y)) continue;
            
            int dist = abs(x - p[0]) + abs(y - p[1]);
            if (dist < minDist) {
                minDist = dist;
                sol = i;
            }
        }
        return sol;
    }
};