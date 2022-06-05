class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mincost=prices[0],profit=0;
        for(int i=1;i<prices.size();i++)
        {
            int cost=prices[i]-mincost;
            profit=max(profit,cost);
            mincost=min(mincost,prices[i]);
        }
        return profit;
    }
};