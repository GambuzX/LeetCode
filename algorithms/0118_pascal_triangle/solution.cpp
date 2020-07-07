class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> rows(numRows, vector<int>());
        for (int i = 0; i < numRows; i++)
            rows[i].resize(i+1);
        
        for (int r = 0 ; r < numRows; r++) {
            vector<int> & row = rows[r];
            row[0] = 1;
            row[row.size()-1] = 1;
            if (r == 0) continue;
            vector<int> & prev = rows[r-1];
            for (int i = 1; i < row.size()-1; i++) {
                row[i] = prev[i-1] + prev[i];
            }
        }
        
        return rows;
    }
};