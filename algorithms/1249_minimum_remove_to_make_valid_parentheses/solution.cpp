class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<int> opening;
        
        for(int i = 0; i < s.length(); i++) {
            if (s[i] == '(') opening.push(i);
            
            if (s[i] == ')') {
                if(!opening.empty()) opening.pop();
                else s[i] = '*';
            }
        }
        
        while(!opening.empty()) {
            s[opening.top()] = '*';
            opening.pop();
        }
        
        s.erase(remove(s.begin(), s.end(), '*'), s.end());
        return s;
    }
};