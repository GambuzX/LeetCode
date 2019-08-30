class Solution {
public:
    int search(vector<int>& nums, int target) {
        int i1 = 0, i2 = nums.size()-1;
        
        while(i1 <= i2) {
            
            int mid = (i1+i2)/2;
            
            if (nums[mid] == target) return mid;
            if (nums[i1] == target) return i1;
            if (nums[i2] == target) return i2;
            
            if (target >= nums[i1] && target < nums[mid]) {
                i2 = mid-1;
            }
            else if (nums[i1] > nums[mid] && (target < nums[mid] || target > nums[i1])) {
                i2 = mid-1;
            }
            else  {
                i1 = mid+1;
            }            
        }
        
        return -1;
    }
};