class Solution {
public:
    int maxSatisfaction(vector<int>& satisfaction) {
        int N = satisfaction.size();
        sort(begin(satisfaction), end(satisfaction));
        
        int max_found = INT_MIN;
        for (int ndishes = 0; ndishes <= N; ndishes++) { // number of considered dishes
            int curr = 0;
            for (int i = 0; i < ndishes; i++) {
                curr += (i+1) * satisfaction.at(N-ndishes+i);
            }
            max_found = max(max_found, curr);
        }
        return max_found;
    }
};