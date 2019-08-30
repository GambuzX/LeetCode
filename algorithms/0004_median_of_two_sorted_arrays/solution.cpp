class Solution {
public:
    double min(double a, double b) {
        return a > b ? b : a;
    }
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size(), n = nums2.size();
        int i1 = 0, i2 = 0, last = 0, prev = 0;
        int iters = (n+m)/2;
        
        if (m == 0) last = nums2.at(0);
        if (n == 0) last = nums1.at(0);
        if (m > 0 && n > 0) last = min(nums1.at(0), nums2.at(0));
        
        while(i1 < m && i2 < n && iters) {
            prev = last;
            if (nums1.at(i1) > nums2.at(i2)) {
                i2++;
                if (i2 >= n) last = nums1.at(i1);
                else last = min(nums1.at(i1), nums2.at(i2));
            }
            else {
                i1++;
                if (i1 >= m) last = nums2.at(i2);
                else last = min(nums1.at(i1), nums2.at(i2));
            }
            iters--;
        }
        
        while(i1 < m && iters) {
            prev = last;
            i1++;
            last = nums1.at(i1);
            iters--;
        }
        while(i2 < n && iters) {
            prev = last;
            i2++;
            last = nums2.at(i2);
            iters--;
        }
        
        return (n+m) % 2 == 0 ? ((double) last + prev) / 2 : last;        
    }
};