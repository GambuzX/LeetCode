class Solution {
public:
    int singleNumber(vector<int>& nums) {
        map<int, int> num_counts;
        for (int n : nums)
            num_counts[n]++;
        
        for (auto ele : num_counts)
            if (ele.second == 1)
                return ele.first;
        return 0;
    }
};