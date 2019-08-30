class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0;
        
        if (prices.size() == 0) return 0;
        
        int buy = -1, curr = 0;
        while ( curr < prices.size()-1) {
            if (buy == -1) {
                if (prices[curr+1] > prices[curr])
                    buy = curr;
            }
            else {
                if (prices[curr+1] <= prices[curr]) {
                    profit += prices[curr] - prices[buy];
                    buy = -1;
                }
                
            }            
            
            curr++;
        }
        
        if (buy != -1 && prices[prices.size()-1] > prices[buy]) profit += prices[prices.size()-1] - prices[buy];
        
        return profit;
    }
};