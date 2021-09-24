class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int total = 0;
        
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        
        int childI = g.size()-1, cookieI = s.size()-1;
        while(childI >= 0 && cookieI >= 0) {
            if(s[cookieI] >= g[childI]) {
                total++;
                cookieI--;
            } 
            childI--;
        }
        
        return total;
    }
};