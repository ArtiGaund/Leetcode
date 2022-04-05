class Solution {
public:
    int climbStairs(int n) {
        vector<int> dp(n+1,-1);
        return solve(dp,n);
    }
    int solve(vector<int> &dp,int n)
    {
        if(dp[n]==-1)
        {
            if(n==1) dp[n]=1;
            else if(n==2) dp[n]=2;
            else
                dp[n]=solve(dp,n-1)+solve(dp,n-2);
        }
        return dp[n];
    }
};