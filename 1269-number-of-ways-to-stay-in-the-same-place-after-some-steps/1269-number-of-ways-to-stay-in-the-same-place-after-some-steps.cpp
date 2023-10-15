class Solution {
public:
    vector<vector<int>> dp;
    int mod=1e9+7;
    int arrLen;
    int solve(int cur,int remain)
    {
        if(remain==0)
        {
            if(cur==0) return 1;
            return 0;
        }
        if(dp[cur][remain]!=-1)
            return dp[cur][remain];
        int res=solve(cur,remain-1);
        if(cur>0) res=(res+solve(cur-1,remain-1))%mod;
        if(cur<arrLen-1) res=(res+solve(cur+1,remain-1))%mod;
        dp[cur][remain]=res;
        return res;
    }
    int numWays(int steps, int arrLen) {
        arrLen=min(steps,arrLen);
        this->arrLen=arrLen;
        dp=vector(arrLen,vector(steps+1,-1));
        return solve(0,steps);
    }
};