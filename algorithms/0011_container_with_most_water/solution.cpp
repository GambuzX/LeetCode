class Solution {
public:
    
    
    int maxArea(vector<int>& height) {
        int max_a = 0;        
        int left = 0, right = height.size()-1;
        
        while(left < right) {
            int area = (right - left) * min(height[left], height[right]);
            
            max_a = max(max_a, area);
            
            if (height[right] > height[left])
                left++;
            else
                right--;
        }
        
        return max_a;
    }
};