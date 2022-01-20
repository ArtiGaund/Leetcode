class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        vector<vector<int>> dp(n,vector<int>(amount+1,-1));
        int res=solve(coins,dp,amount,0);
        return (res==INT_MAX?-1:res);
    }
    int solve(vector<int> &coins,vector<vector<int>> &dp,int amount,int i)
    {
        if(amount==0) return 0;
        if(coins.size()==0 or i>=coins.size()) return INT_MAX;
        if(dp[i][amount]==-1)
        {
            int count1=INT_MAX;
            if(coins[i]<=amount)
            {
                int res=solve(coins,dp,amount-coins[i],i);
                if(res!=INT_MAX)
                    count1=res+1;
            }
            int count2=solve(coins,dp,amount,i+1);
            dp[i][amount]=min(count1,count2);
        }
        return dp[i][amount];
    }
};