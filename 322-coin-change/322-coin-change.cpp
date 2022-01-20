class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        vector<vector<int>> dp(n,vector<int>(amount+1,-1));
        int res=solve(coins,dp,amount,0);
        return (res==INT_MAX?-1:res);
    }
    int solve(vector<int> &v,vector<vector<int>> &dp,int amount,int i)
    {
        if(amount==0) return 0;
        if(i>=v.size() or v.size()==0) return INT_MAX;
        if(dp[i][amount]==-1)
        {
            int sum1=INT_MAX;
            if(v[i]<=amount)
            {
                int res=solve(v,dp,amount-v[i],i);
                if(res!=INT_MAX) sum1=res+1;
            }
            int sum2=solve(v,dp,amount,i+1);
            dp[i][amount]=min(sum1,sum2);
        }
        return dp[i][amount];
    }
};