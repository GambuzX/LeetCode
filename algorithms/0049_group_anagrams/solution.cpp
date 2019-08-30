class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> used;
        
        for (string & word : strs) {
            // count chars
            vector<int> count(26,0);            
            for (char & c : word)
                count[c -'a']++;
            
            // build string
            string s = "";
            for (int & i : count)
                s += "#" + to_string(i);
            
            // check if repeated
            if (used.find(s) == used.end()) {
                used[s] = vector<string>();
            }
            
            used.find(s)->second.push_back(word);
        }
        
        vector<vector<string>> result;
        
        for (auto & item : used)
            result.push_back(item.second);
        
        return result;
    }
};