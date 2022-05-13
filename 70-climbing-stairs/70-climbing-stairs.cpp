class Solution {
public:
    int climbStairs(int n) {
        vector<int> dp(n+1,-1);
        return topDown(n,dp);
    }
    int topDown(int n,vector<int> &dp)
    {
        if(n<=1) return dp[n]=1;
        if(dp[n]!=-1) return dp[n];
        return dp[n]=topDown(n-1,dp)+topDown(n-2,dp);
    }
};