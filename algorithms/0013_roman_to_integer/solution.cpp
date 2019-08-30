class Solution {
public:
    int convert_symbol(char c) {
        switch (c) {
            case 'I':
                return 1;
            case 'V':
                return 5;
            case 'X':
                return 10;
            case 'L':
                return 50;
            case 'C':
                return 100;
            case 'D':
                return 500;
            case 'M':
                return 1000;
            }
        return 0;
    }
    
    int romanToInt(string s) {
        int total = 0;
            
        for(int i = 0; i < s.length(); i++) {
            char curr = s[i];
            if(i == s.length()-1)  {
                total += convert_symbol(curr);
                continue;
            }
            char next = s[i+1];
            if ((curr == 'I' && next == 'V') || (curr == 'I' && next == 'X')) {
                total += convert_symbol(next)-1;
                i++;
            }
            else if ((curr == 'X' && next == 'L') || (curr == 'X' && next == 'C')) {
                total += convert_symbol(next)-10;
                i++;
            }
            else if ((curr == 'C' && next == 'D') || (curr == 'C' && next == 'M')) {
                total += convert_symbol(next)-100;
                i++;
            }
            else {
                total += convert_symbol(curr);
            }
        }
        
        return total;        
    }
};