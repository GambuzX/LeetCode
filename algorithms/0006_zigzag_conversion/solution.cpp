class Solution {
public:
    string convert(string s, int numRows) {
        string ret = "";
        
        for(int i = 0; i < numRows; i++) {
            int space1 = (numRows - 1 -i) * 2;
            int space2 = i*2;
            bool s1 = true;
            int j = i;
            
            while(j < s.length()) {
                ret += s[j];
                if (space1 == 0 && space2 == 0) j++;
                else if (space1 == 0) j += space2;
                else if (space2 == 0) j+= space1;
                else if (s1) j += space1;
                else j += space2;
                s1 = !s1;
            }
        }
        
        return ret;
    }
};