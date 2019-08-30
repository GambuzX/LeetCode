class Solution {
public:
    int myAtoi(string str) {
        
        int i = 0;
        while (str[i] == ' ') i++;
        bool neg = false;
        if (str[i] == '-') {
            neg = true;
            i++;
        }
        else if (str[i] == '+') i++;
        
        bool first = true;
        int res = 0;
        while(isdigit(str[i])) {
            
            //int curr = neg ? res * -1 : res;            
            if (res > (INT_MAX - str[i]+'0')/10) return INT_MAX;
            if (res < (INT_MIN + str[i] - '0')/10) return INT_MIN;
            
            if (first) {
                res = res * 10 + (str[i]-'0');
                res = neg ? res * -1 : res;               
                first = false;
            }
            else {
                if (!neg) res = res * 10 + (str[i]-'0');
                else res = res * 10 - (str[i]-'0');
            }
            i++;
        }
        
        return res;
        
    }
};