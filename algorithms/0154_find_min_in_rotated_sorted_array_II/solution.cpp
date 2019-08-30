bool is_min(vector<int>& vec, int index) {
    int left_bound = index-1;
    if (left_bound < 0) left_bound += vec.size();
    
    int right_bound = (index+1) % vec.size();
    
    int iters = 1;
    while(vec[left_bound] == vec[index]) {
        left_bound--;
        iters++;
        if (left_bound < 0) left_bound += vec.size();    
        if (iters >= vec.size()) return true;
    }
    
    iters=1;
    while(vec[right_bound] == vec[index]) {
        iters++;
        right_bound = (right_bound+1) % vec.size();
        if (iters >= vec.size()) return true;
    }
    
    return vec[index] < vec[left_bound] && vec[index] < vec[right_bound];
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
            
            if (nums[mid] == nums[right] && nums[mid] == nums[left]) {
                left++;
                right--;
            }
            else if (nums[mid] > nums[right]) {
                left = mid+1;
            }
            else {
                right = mid-1;
            }
        }
        
        return -1;
    }
};