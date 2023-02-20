class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minCost=prices[0],profit=0;
        for(int i=1;i<prices.size();i++)
        {
            int cost=prices[i]-minCost;
            profit=max(profit,cost);
            minCost=min(minCost,prices[i]);
        }
        return profit;
    }
};