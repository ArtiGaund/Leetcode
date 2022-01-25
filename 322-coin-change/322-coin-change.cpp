class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        if(n==0) return 0;
        vector<vector<int>> dp(n,vector<int>(amount+1,-1));
        int res=solve(coins,amount,dp,0);
        return (res==INT_MAX?-1:res);
    }
    int solve(vector<int> &coins,int amount,vector<vector<int>> &dp,int i)
    {
        if(amount==0) return 0;
        if(coins.size()==0 or i>=coins.size()) return INT_MAX;
        if(dp[i][amount]==-1)
        {
            int c1=INT_MAX;
            if(coins[i]<=amount)
            {
                int res=solve(coins,amount-coins[i],dp,i);
                if(res!=INT_MAX)
                    c1=res+1;
            }
            int c2=solve(coins,amount,dp,i+1);
            dp[i][amount]=min(c1,c2);
        }
        return dp[i][amount];
            
    }
};