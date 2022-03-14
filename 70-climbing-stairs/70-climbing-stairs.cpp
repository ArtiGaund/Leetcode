class Solution {
public:
    int climbStairs(int n) {
        vector<int> dp(n+1,-1);
        return topdown(n,dp);
    }
    int topdown(int n,vector<int> &dp)
    {
        if(n<2) return 1;
        if(n==2) return 2;
        if(dp[n]==-1)
        {
            int step1=topdown(n-1,dp);
            int step2=topdown(n-2,dp);
            dp[n]=step1+step2;
        }
        return dp[n];
    }
};