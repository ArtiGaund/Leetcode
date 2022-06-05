class Solution {
public:
   
    int maxProfit(int k, vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>> dp(n+1,vector<int>(2*k+1,0));
        for(int index=n-1;index>=0;index--)
        {
            for(int trans=2*k-1;trans>=0;trans--)
            {
                if(trans%2==0)
                {
                    int take=-prices[index]+dp[index+1][trans+1];
                    int nottake=0+dp[index+1][trans];
                    dp[index][trans]=max(take,nottake);
                }
                else
                {
                    int take=prices[index]+dp[index+1][trans+1];
                    int nottake=0+dp[index+1][trans];
                    dp[index][trans]=max(take,nottake);
                }
            }
        }
        return dp[0][0];
    }
};