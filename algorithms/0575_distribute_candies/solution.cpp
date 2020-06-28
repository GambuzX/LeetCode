class Solution {
public:
    int distributeCandies(vector<int>& candies) {
        unordered_set<int> seen;
        for (int i : candies) {
            seen.insert(i);
        }        
        return min(candies.size()/2, seen.size());
    }
};