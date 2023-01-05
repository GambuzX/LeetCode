class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res;
        unordered_set<int> n1;
        unordered_set<int> seen;
        for (int n : nums1) n1.insert(n);
        for (int n : nums2) {
            if (n1.find(n) != n1.end() && seen.find(n) == seen.end()) {
                res.push_back(n);
                seen.insert(n);
            }
        }
        return res;
    }
};