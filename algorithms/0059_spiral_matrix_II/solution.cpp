class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> res(n, vector<int>(n));
        
        int curr = 1;
        int l = 0, r = n-1;
        int t = 0, b = n-1;
        while(curr <= pow(n,2)) {
            for (int i = l; i <= r; i++) {
                res[t][i] = curr++;
            }
            for (int i = t+1; i <= b; i++) {
                res[i][r] = curr++;
            }
            for (int i = r-1; i >= l; i--) {
                res[b][i] = curr++;
            }
            for (int i = b-1; i > t; i--) {
                res[i][l] = curr++;
            }
            
            l++; r--;
            t++; b--;
        }
        
        return res;
    }
};