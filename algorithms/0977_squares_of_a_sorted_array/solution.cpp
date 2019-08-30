class Solution {
public:
    vector<int> sortedSquares(vector<int>& A) {
        vector<int> ret_a;
        if (A.size() == 0) return ret_a;
        if (A.size() == 1) {
            ret_a.push_back(A.at(0) * A.at(0));
            return ret_a;
        }
        
        int mid = 0;
        for (int i = 1 ; i < A.size(); i++) {
            if (A.at(0) * A.at(i) <= 0) {
                mid = i;
                break;
            }
        }
             
        int i1 = mid-1 , i2 = mid;
        
        int sq1, sq2;
        while(i1 >= 0 && i2 < A.size()) {
            sq1 = A.at(i1) * A.at(i1);
            sq2 = A.at(i2) * A.at(i2);
            if (sq1 > sq2) {
                ret_a.push_back(sq2);
                i2++;
            }
            else {
                ret_a.push_back(sq1);
                i1--;
            }
        }
        
        while(i1>=0) {
            sq1 = A.at(i1) * A.at(i1);
            ret_a.push_back(sq1);
            i1--;
        }
        while(i2 < A.size()) {
            sq2 = A.at(i2) * A.at(i2);
            ret_a.push_back(sq2);
            i2++;
        }       
        
        
        return ret_a;
    }
};