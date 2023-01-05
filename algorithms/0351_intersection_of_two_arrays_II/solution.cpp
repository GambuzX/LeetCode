class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res;
        unordered_map<int, int> n1;
        unordered_map<int, int> seen;
        for (int n : nums1) n1[n]++;
        for (int n : nums2) {
            if (n1.find(n) == n1.end()) continue;
            int cap = n1[n];
            int curr = seen[n];

            if (curr < cap) {
                res.push_back(n);
                seen[n]++;
            }
        }
        return res;
    }
};