class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<int> f1(2,0),f2(2,0),cur(2,0);
        for(int index=n-1;index>=0;index--)
        {
            cur[1]=max(-prices[index]+f1[0],0+f1[1]);
            cur[0]=max(prices[index]+f2[1],0+f1[0]);
            f2=f1;
            f1=cur;
        }
        return cur[1];
    }
};