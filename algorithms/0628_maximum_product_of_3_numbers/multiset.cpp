class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        multiset<int> numbers;
        for(int num : nums) numbers.insert(num);
        
        int pos_prod = 1;
        int neg_prod = 1;
        
        multiset<int>::iterator it = numbers.end();
        it--;
        for(int i = 0; i < 3; i++, it--) pos_prod *= *it;
        
        it = numbers.end(); it--;
        neg_prod *= *it;
        it = numbers.begin();
        for(int i = 0; i < 2; i++, it++) neg_prod *= *it;
        
        return max(pos_prod, neg_prod);
    }
};