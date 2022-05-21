class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        int max=amount+1;
        vector<int> dp(amount+1,max);
        dp[0]=0;
        for(int i=0;i<n;i++)
        {
            for(int j=coins[i];j<=amount;j++)
                dp[j]=min(dp[j],dp[j-coins[i]]+1);
        }
        return dp[amount]>amount?-1:dp[amount];
    }
};