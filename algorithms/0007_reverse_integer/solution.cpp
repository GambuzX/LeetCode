class Solution {
public:
    int reverse(int x) {
        string output = "";
        string ori = to_string(x);
        bool sign = (ori[0] == '-');
        
        for (int i = ori.length()-1; i >= (sign ? 1 : 0); i--) {
            output += ori[i];
        }
        if (sign) output = "-" + output;
        
        try {
            return stoi(output);
        }
        catch(...) {
            return 0;
        }
    }
};