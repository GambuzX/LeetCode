class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int l = 0, r = k-1;
        vector<int> sol;
        for (; r < nums.size(); l++, r++) {
            int m = nums[l];
            for (int i = l+1; i <= r; i++)
                m = max(m, nums[i]);
            sol.push_back(m);
        }
        
        return sol;
    }
};