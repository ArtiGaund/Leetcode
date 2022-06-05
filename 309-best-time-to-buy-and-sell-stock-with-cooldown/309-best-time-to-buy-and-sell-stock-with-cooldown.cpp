class Solution {
public:
    int solve(vector<int> &prices,vector<vector<int>> &dp,int n,int index,int buy)
    {
        if(index>=n) return 0;
        if(dp[index][buy]!=-1) return dp[index][buy];
        if(buy)
        {
            int take=-prices[index]+solve(prices,dp,n,index+1,0);
            int nottake=0+solve(prices,dp,n,index+1,1);
            return dp[index][buy]=max(take,nottake);
        }
        else
        {
            int take=prices[index]+solve(prices,dp,n,index+2,1);
            int nottake=0+solve(prices,dp,n,index+1,0);
            return dp[index][buy]=max(take,nottake);
        }
    }
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>> dp(n+2,vector<int>(2,0));
        for(int i=n-1;i>=0;i--)
        {
            for(int buy=0;buy<=1;buy++)
            {
                if(buy)
                {
                    int take=-prices[i]+dp[i+1][0];
                    int nottake=0+dp[i+1][1];
                    dp[i][buy]=max(take,nottake);
                }
                else
                {
                    int take=prices[i]+dp[i+2][1];
                    int nottake=0+dp[i+1][0];
                    dp[i][buy]=max(take,nottake);
                }
            }
        }
        return dp[0][1];
    }
};