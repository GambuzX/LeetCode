bool is_min(vector<int>& vec, int index) {
    int left_bound = index-1;
    if (left_bound < 0) left_bound += vec.size();
    
    return vec[index] <= vec[left_bound];
}

class Solution {
public:
    int findMin(vector<int>& nums) {
        int left = 0, right = nums.size()-1;
        
        while(right >= left) {
            int mid = (left+right)/2;
            
            if (is_min(nums, mid)) return nums[mid];
            if (is_min(nums, left)) return nums[left];
            if (is_min(nums, right)) return nums[right];
            
            if (nums[mid] > nums[right]) {
                left = mid+1;
            }
            else {
                right = mid-1;
            }
        }
        
        return -1;
    }
};