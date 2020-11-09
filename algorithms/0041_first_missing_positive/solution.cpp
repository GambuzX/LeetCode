class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        unordered_set<int> seen;
        int min_missing = 1;
        for(int n : nums) {
            seen.insert(n);
            if (min_missing == n) {
                while(seen.find(min_missing) != seen.end())
                    min_missing++;
            }
        }
        return min_missing;
    }
};