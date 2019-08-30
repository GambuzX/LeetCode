class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        
        if (nums.size() == 0) return 0;
        
        int new_size = 0;
        int previous = nums[0];
        int insert_index = 1;
        
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] != previous) {
                previous = nums[i];
                nums[insert_index++] = nums[i];
                new_size++;
            }
        }
        
        return insert_index;
        
    }
};