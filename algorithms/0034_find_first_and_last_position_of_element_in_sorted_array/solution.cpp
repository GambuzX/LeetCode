class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if (nums.size() == 0) return {-1,-1};
        
        vector<int> res(2, -1);        
        int l = 0, r = nums.size()-1;
        while(true) {
            int mid = (l+r)/2;
            
            if (nums[mid] == target) {
                res = {mid, mid};
                break;
            }
            else if (nums[mid] < target) {
                l = mid+1;
            }
            else {
                r = mid-1;
            }
            
            if (l > r) return {-1,-1};
        }
        
        while(res[0] >= 0 && nums[res[0]] == target) res[0]--;
        while(res[1] < nums.size() && nums[res[1]] == target) res[1]++;
        
        res[0]++;
        res[1]--;
        return res;
    }
};