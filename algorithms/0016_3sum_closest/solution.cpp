class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        
        long long int res_sum = INT_MAX;
        
        for (int i = 0; i < nums.size(); i++) {
            int i1 = i+1;
            int i2 = nums.size()-1;
            while(i1 < i2) {
                int front = nums[i1];
                int back = nums[i2];
                
                int sum = nums[i] + front + back;
                if (abs(target - sum) < abs(target - res_sum))
                    res_sum = sum;
                
                if (sum == target) {
                    return sum;
                }
                else if (sum > target) {
                    i2--;
                }
                else {
                    i1++;
                }
            }
        }
        
        return (int) res_sum;
    }
};