class Solution {
public:
    string reverseWords(string s) {
        string final_str = "";
        int iter;
        iter = s.find_first_of(" ");
        while(iter != string::npos) {
            string slice = s.substr(0, iter);
            for (int i = slice.length()-1; i >= 0; i--)
                final_str += slice[i];
            final_str += " ";
            
            s = s.substr(iter+1);
            iter = s.find_first_of(" ");            
        }
        for (int i = s.length()-1; i >= 0; i--)
            final_str += s[i];
        return final_str;
    }
};