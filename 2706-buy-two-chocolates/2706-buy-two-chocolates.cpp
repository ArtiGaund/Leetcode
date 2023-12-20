class Solution {
public:
    int buyChoco(vector<int>& prices, int money) {
        int mini=min(prices[0],prices[1]);
        int secMini=max(prices[0],prices[1]);
        for(int i=2;i<prices.size();i++){
            if(prices[i]<mini){
                secMini=mini;
                mini=prices[i];
            }else if(prices[i]<secMini) secMini=prices[i];
        }
        int minCost=mini+secMini;
        return money>=minCost?money-minCost:money;
    }
};