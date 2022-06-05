class Solution {
public:
    int solve(vector<int> &prices,vector<vector<int>> &dp,int n,int k,int index,int trans)
    {
        if(index==n or trans==2*k) return 0;
        if(dp[index][trans]!=-1) return dp[index][trans];
        int profit=0;
        if(trans%2==0) //buy
        {
            int take=-prices[index]+solve(prices,dp,n,k,index+1,trans+1);
            int nottake=0+solve(prices,dp,n,k,index+1,trans);
            profit=max(take,nottake);
        }
        else
        {
            int take=prices[index]+solve(prices,dp,n,k,index+1,trans+1);
            int nottake=0+solve(prices,dp,n,k,index+1,trans);
            profit=max(take,nottake);
        }
        return dp[index][trans]=profit;
    }
    int maxProfit(int k, vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>> dp(n,vector<int>(2*k,-1));
        return solve(prices,dp,n,k,0,0);
    }
};