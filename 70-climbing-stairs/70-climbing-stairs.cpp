class Solution {
public:
    int climbStairs(int n) {
        vector<int> dp(n+1,0);
        return solve(dp,n);
    }
    int solve(vector<int> &dp,int n)
    {
        if(n<=1) return 1;
        if(n==2) return 2;
        if(dp[n]==0)
        {
            int step1=solve(dp,n-1);
            int step2=solve(dp,n-2);
            dp[n]=step1+step2;
        }
        return dp[n];
    }
};