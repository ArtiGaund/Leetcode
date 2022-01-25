class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        vector<vector<int>> dp(n,vector<int>(amount+1,-1));
        int res=solve(dp,coins,amount,0);
        return res==INT_MAX?-1:res;
    }
    int solve(vector<vector<int>> &dp,vector<int> &coins,int amount,int i)
    {
        if(amount==0) return 0;
        if(coins.size()==0 or i>=coins.size()) return INT_MAX;
        if(dp[i][amount]==-1)
        {
            int c1=INT_MAX;
            if(coins[i]<=amount)
            {
                int res=solve(dp,coins,amount-coins[i],i);
                if(res!=INT_MAX) c1=res+1;
            }
            int c2=solve(dp,coins,amount,i+1);
            dp[i][amount]=min(c1,c2);
        }
        return dp[i][amount];
    }
};