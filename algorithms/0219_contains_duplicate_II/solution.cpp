class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, vector<int>> positions;
        
        for (int i = 0 ; i < nums.size(); i++) {
            unordered_map<int, vector<int>>::iterator it = positions.find(nums[i]);
            if (it == positions.end())
                positions.insert(pair<int, vector<int>>(nums[i], vector<int>(1, i)));
            else
                it->second.push_back(i);
        }
        
        for (int i = 0; i < nums.size(); i++) {
            unordered_map<int, vector<int>>::iterator it = positions.find(nums[i]);

            vector<int> & same = it->second;
            for (int j = 0; j < same.size(); j++) {
                if (i == same[j]) continue;
                if (abs(i-same[j]) <= k) return true;
            }            
        }
        return false;
    }
};