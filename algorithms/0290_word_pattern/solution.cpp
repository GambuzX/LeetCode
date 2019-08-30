class Solution {
public:
    bool wordPattern(string pattern, string str) {
        unordered_map<char, string> letter_name;
        unordered_map<string, char> name_letter;
        unordered_map<char, string>::iterator it1;
        unordered_map<string, char>::iterator it2;
        
        int str_i = 0;
        size_t next_space = 1;
        for (int i = 0 ; i < pattern.length(); i++) {
            if (next_space == string::npos) return false;
            next_space = str.find_first_of(' ', str_i);
            string curr;
            if (next_space != string::npos) {
                curr = str.substr(str_i, next_space - str_i);
                str_i = next_space + 1;
            }
            else {
                curr = str.substr(str_i);
            }
            
            it1 = letter_name.find(pattern[i]);
            it2 = name_letter.find(curr);
            if (it1 == letter_name.end() && it2 == name_letter.end()) {
                letter_name.insert(pair<char,string>(pattern[i], curr));
                name_letter.insert(pair<string, char>(curr, pattern[i]));
            }
            else if (it1 == letter_name.end() && it2 != name_letter.end()) {
                return false;
            }
            else if (it1 != letter_name.end() && it2 == name_letter.end()) {
                return false;
            }
            else {
                if(it1->second != it2->first || it1->first != it2->second)
                    return false;
            }
        }
        if (next_space != string::npos) return false;
        return true;        
    }
};