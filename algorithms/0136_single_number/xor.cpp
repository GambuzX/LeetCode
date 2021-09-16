class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int coiso = nums[0];
        for(int i = 1; i < nums.size(); i++) coiso ^= nums[i];
        return coiso;
    }
};