class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.size() == 0) return "";
        string comp = strs[0];
        
        int max = 0;
        for (int i = 1 ; i <= comp.length(); i++) {
            bool valid = true;
            for (int j = 1; j < strs.size(); j++) {
                if (strs[j].find(comp.substr(0, i)) != 0) {
                    valid = false;
                    break;
                }
            }
            if (!valid) break;
            max = i;
        }
        return comp.substr(0,max);
    }
};