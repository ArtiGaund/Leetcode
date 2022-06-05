class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int prevbuy,prevnotbuy,curbuy,curnotbuy;
        prevbuy=prevnotbuy=0;
        int n=prices.size();
        for(int index=n-1;index>=0;index--)
        {
            //sell 
            curnotbuy=max(prices[index]-fee+prevbuy,0+prevnotbuy);
            // buy
            curbuy=max(-prices[index]+prevnotbuy,0+prevbuy);
            prevbuy=curbuy;
            prevnotbuy=curnotbuy;
        }
        return prevbuy;
    }
};