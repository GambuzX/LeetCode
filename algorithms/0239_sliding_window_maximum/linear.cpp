class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> Q(k);
        vector<int> sol;
        
        for (int i = 0; i < k; i++) {            
            while(!Q.empty() && nums[i] >= nums[Q.back()])
                Q.pop_back();
            Q.push_back(i);
        }
        
        for (int i = k; i < nums.size(); i++) {
            sol.push_back(nums[Q.front()]);
            
            while(!Q.empty() && Q.front() <= i-k) 
                Q.pop_front();
            
            while(!Q.empty() && nums[i] >= nums[Q.back()]) 
                Q.pop_back();
            
            Q.push_back(i);
        }
        sol.push_back(nums[Q.front()]);
        
        return sol;
    }
};