class Solution {
public:
    void shift_right(vector<int>& arr, int first, int last) {
        for (int i = last; i > first; i--) {
            arr.at(i) = arr.at(i-1);
        }
    }
    
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i1 = 0, i2 = 0;
        int ori_size = n + m;
        while(i1 < m && i2 < n) {
            if (nums1.at(i1) > nums2.at(i2)) {
                shift_right(nums1, i1, ori_size-1);
                nums1.at(i1) = nums2.at(i2);
                m++;
                i2++;
            }
            i1++;
        }
        
        while(i2 < n) {
            nums1.at(i1) = nums2.at(i2);
            i1++;
            i2++;
        }        
        
    }
};