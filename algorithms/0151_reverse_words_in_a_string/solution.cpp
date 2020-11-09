class Solution {
public:
    string reverseWords(string s) {
        istringstream iss(s);
        string s2;
        stack<string> words;
        while(iss >> s2) {
            words.push(s2);
        }
        string res = "";
        while(!words.empty()) {
            res += words.top();
            words.pop();
            if(!words.empty()) 
                res += " ";
        }
        return res;
    }
};