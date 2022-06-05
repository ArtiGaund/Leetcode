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
        vector<vector<int>> dp(n,vector<int>(2,-1));
        return solve(prices,dp,n,0,1);
    }
};