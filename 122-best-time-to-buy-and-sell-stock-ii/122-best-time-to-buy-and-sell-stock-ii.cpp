class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>> dp(n+1,vector<int>(2));
        dp[n][0]=dp[n][1]=0;
        for(int index=n-1;index>=0;index--)
        {
            for(int buy=0;buy<=1;buy++)
            {
                int profit=0;
                if(buy)
                {
                    int take=-prices[index]+dp[index+1][0];
                    int nottake=0+dp[index+1][1];
                    profit=max(take,nottake);
                }
                else
                {
                    int take=prices[index]+dp[index+1][1];
                    int nottake=0+dp[index+1][0];
                    profit=max(take,nottake);
                }
                dp[index][buy]=profit;
            }
        }
        return dp[0][1];
    }
};