class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        vector<vector<int>> dp(n,vector<int>(amount+1,INT_MAX));
        for(int i=0;i<n;i++)
            dp[i][0]=0;
        for(int i=0;i<n;i++)
        {
            for(int j=1;j<=amount;j++)
            {
                if(i>0) dp[i][j]=dp[i-1][j];
                if(j>=coins[i])
                {
                    if(dp[i][j-coins[i]]!=INT_MAX)
                        dp[i][j]=min(dp[i][j],dp[i][j-coins[i]]+1);
                }
            }
        }
        return dp[n-1][amount]==INT_MAX?-1:dp[n-1][amount];
    }
};