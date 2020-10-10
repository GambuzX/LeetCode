class Solution {
private:
    int N;
    vector<string> ans;
public:
    void backtrack(string S, int left, int right) {
        if(S.length() == 2*N) {
            ans.push_back(S);
            return;
        }
        
        if (left < N)
            backtrack(S + "(", left+1, right);
        if (left > right)
            backtrack(S + ")", left, right+1);
    }
    
    vector<string> generateParenthesis(int n) {
        this->N = n;
        backtrack("", 0, 0);
        return ans;
    }
};