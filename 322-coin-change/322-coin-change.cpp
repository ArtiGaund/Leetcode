class Solution {
public:
    int dp[10000+1][12+1];
    int coinChange(vector<int>& coins, int amount) {
        memset(dp,-1,sizeof(dp));
        int mincoin=solve(coins,amount,coins.size());
        return (mincoin==INT_MAX-1?-1:mincoin);
    }
    int solve(vector<int> &coins,int amount,int n)
    {
        if(n==0 or amount==0) return (amount==0?0:INT_MAX-1);
        if(dp[amount][n]!=-1) return dp[amount][n];
        if(coins[n-1]>amount)
            return dp[amount][n]=0+solve(coins,amount-0,n-1);
        else
            return dp[amount][n]=min(0+solve(coins,amount-0,n-1),1+solve(coins,amount-coins[n-1],n));
    }
};