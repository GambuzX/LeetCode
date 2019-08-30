class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) return false;
        
        stack<int> stk;
        int n_digits = 0;
        int cpy = x;
        while(cpy > 0) {
            n_digits++;
            cpy /= 10;
        }
        
        for (int i = 0; i < n_digits / 2; i++) {
            stk.push(x % 10);
            x = x / 10;
        }
        if (n_digits % 2) x /= 10;
        
        while(!stk.empty()) {
            if (stk.top() != (x % 10)) return false;
            stk.pop();
            x /= 10;
        }
        return true;
    }
};