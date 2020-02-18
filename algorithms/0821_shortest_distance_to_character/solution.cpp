class Solution {
public:
    vector<int> shortestToChar(string S, char C) {
        vector<int> dists(S.length(), 0);
        
        set<int> c_pos;
        for(int i = 0; i < S.length(); i++) {
            if (S[i] == C)
                c_pos.insert(i);
        }
        
        set<int>::iterator it = c_pos.begin();
        
        int i1 = -1, i2 = *it;
        it++;
        for (int i = 0; i < S.length(); i++) {
            if (i == i2) {
                i1 = i2;
                i2 = (it == c_pos.end() ? -1 : *it);
                it++;
                continue;
            }
            
            if (i1 == -1 && i < i2) {
                dists[i] = i2 - i;
            }
            else if (i > i1 && i2 == -1) {
                dists[i] = i - i1;
            }
            else if(i1 < i && i < i2) {
                dists[i] = min(i2-i, i-i1);
            }
        }
        
        return dists;
    }
};