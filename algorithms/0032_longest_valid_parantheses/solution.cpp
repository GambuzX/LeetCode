class Solution {
public:
    
    int longestValidParentheses(string s) {
        stack<int> st;
        int n = s.length(), longest = 0;
        
        for (int i = 0; i < n; i++) {
            char c = s[i];
            if (c == '(') {
                st.push(i);
            }
            else {
                if (st.empty() || s[st.top()] != '(') 
                    st.push(i);
                else 
                    st.pop();
            }
        }
        
        if (st.empty()) longest = n;
        else {
            int a = n, b = 0;
            while(!st.empty()) {
                b = st.top(); st.pop();
                longest = max(longest, a - b - 1);
                a = b;
            }
            longest = max(longest, a);
        }
        
        return longest;
    }
};