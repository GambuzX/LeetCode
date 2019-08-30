class Solution {
public:
    bool validMountainArray(vector<int>& A) {
        if (A.size() < 3) return false;
        
        for (int i = 1 ; i < A.size()-1; i++) {
            int peak = A[i];
            
            bool lower = true;
            int prev = peak;
            for (int j = i-1; j >= 0; j--) {
                if (A[j] >= prev) {
                    lower = false;
                    break;
                }
                prev = A[j];
            }
            
            
            if (!lower) continue;
            
            bool higher = true;
            prev = peak;
            for (int j = i+1; j < A.size(); j++) {
                if (A[j] >= prev) {
                    higher = false;
                    break;
                }
                prev = A[j];
            }
            
            if (lower && higher) return true;
        }
        return false;
    }
};