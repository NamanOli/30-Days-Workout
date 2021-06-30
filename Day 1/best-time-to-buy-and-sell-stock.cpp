// https://leetcode.com/problems/best-time-to-buy-and-sell-stock/


// Less Optimized
class Solution {
public:
    int maxProfit(vector<int>& prices) 
    {
        int minPrice=INT_MAX, profit=0;
        for(int i=0; i<prices.size(); ++i) {
            // Min priced stock so far
            minPrice = min(minPrice, prices[i]);
            // profit if stock is sold at current price
            profit = max(profit, prices[i]-minPrice);
            
        }
        return profit;
    }
   
};
