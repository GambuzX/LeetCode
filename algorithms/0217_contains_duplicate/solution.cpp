class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> found;
        for (auto num : nums) {
            pair<unordered_set<int>::iterator, bool> it = found.insert(num);
            if (!it.second)
                return true;
        }
        return false;
    }
};