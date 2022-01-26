class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n=coins.size();
        vector<vector<int>> dp(n,vector<int>(amount+1));
        for(int i=0;i<n;i++)
            dp[i][0]=1;
        for(int i=0;i<n;i++)
        {
            for(int j=1;j<=amount;j++)
            {
                if(i>0) dp[i][j]=dp[i-1][j];
                if(j>=coins[i])
                    dp[i][j]+=dp[i][j-coins[i]];
            }
        }
        return dp[n-1][amount];
    }
    
};