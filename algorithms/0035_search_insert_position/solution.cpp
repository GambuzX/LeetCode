class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int a = 0, b = nums.size()-1, m;
        while(a < b) {
            m = (a+b)/2;
            if (target == nums[m]) return m;
            
            if (target > nums[m]) {
                a = m+1;
            }
            else {
                b = m;
            }
        }
        if (target > nums[b]) return b+1;
        return b;
    }
};