class Solution {
public:
    string int_to_str(int v) {
        switch(v) {
            case 0:
                return "0";
            case 1:
                return "1";
            case 2:
                return "2";
            case 3:
                return "3";
            case 4:
                return "4";
            case 5:
                return "5";
            case 6:
                return "6";
            case 7:
                return "7";
            case 8:
                return "8";
            case 9:
                return "9";
        }
        return "";
    }
    string addStrings(string num1, string num2) {
        
        string ret_string = "";
        int iter1 = num1.length()-1;
        int iter2 = num2.length()-1;
        int carry = 0;
        
        while(iter1 >= 0 && iter2 >= 0) {
            int sum = (num1[iter1]-'0') + (num2[iter2]-'0') + carry;
            if (sum >= 10) {
                carry = 1;
                sum = sum % 10;
            } else carry = 0;
            
            ret_string = int_to_str(sum) + ret_string;
            iter1--;
            iter2--;
        }
        
        while(iter1>=0) {
            int sum = (num1[iter1]-'0') + carry;
            if (sum >= 10) {
                carry = 1;
                sum = sum % 10;
            } else carry = 0;
            
            ret_string = int_to_str(sum) + ret_string;
            iter1--;         
        }
        while(iter2>=0) {
            int sum = (num2[iter2]-'0') + carry;
            if (sum >= 10) {
                carry = 1;
                sum = sum % 10;
            } else carry = 0;
            
            ret_string = int_to_str(sum) + ret_string;
            iter2--;         
        }
        
        if (carry) ret_string = "1" + ret_string;
        
        
        return ret_string;
    }
};