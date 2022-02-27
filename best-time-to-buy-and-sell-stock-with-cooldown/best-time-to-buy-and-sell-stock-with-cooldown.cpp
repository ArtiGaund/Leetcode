class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int endSell=0,endBuy=INT_MIN,prevSell=0,prevBuy=0;
        for(int i=0;i<prices.size();i++)
        {
            prevBuy=endBuy;
            endBuy=max(endBuy,prevSell-prices[i]);
            prevSell=endSell;
            endSell=max(endSell,prevBuy+prices[i]);
        }
        return endSell;
    }
};