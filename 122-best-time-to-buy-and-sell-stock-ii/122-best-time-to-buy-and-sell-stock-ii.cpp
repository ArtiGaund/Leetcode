class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        int prevnot,prevbuy,curnot,curbuy;
        prevnot=prevbuy=0;
        for(int index=n-1;index>=0;index--)
        {
           curbuy=max(-prices[index]+prevnot,0+prevbuy);
            curnot=max(prices[index]+prevbuy,0+prevnot);
            prevnot=curnot;
            prevbuy=curbuy;
        }
        return prevbuy;
    }
};