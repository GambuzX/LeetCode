class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> count;
        for (int n : nums) {
            count[n]++;
            if (count[n] > nums.size()/2) return n;
        }
        return -1;
    }
};