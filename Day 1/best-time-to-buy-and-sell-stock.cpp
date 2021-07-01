// https://leetcode.com/problems/best-time-to-buy-and-sell-stock/



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


// Using Kadane's Algorithm - Maximum Subarray 
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxtillnow=0,maxnow=0;
        for(int i=1;i<prices.size();i++)
        {
            maxnow=max(0,maxnow+=prices[i]-prices[i-1]); // 0 bcoz he has to buy before selling so cant' be negative
            maxtillnow=max(maxtillnow,maxnow);
        }
        return maxtillnow;
    }
    
};
