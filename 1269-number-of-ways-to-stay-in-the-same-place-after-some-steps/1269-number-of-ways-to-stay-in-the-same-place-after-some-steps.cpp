class Solution {
public:
    int numWays(int steps, int arrLen) {
        int mod=1e9+7;
        arrLen=min(steps,arrLen);
        vector dp(arrLen,vector<int>(steps+1,0));
        dp[0][0]=1;
        for(int remain=1;remain<=steps;remain++)
        {
            for(int cur=arrLen-1;cur>=0;cur--)
            {
                int res=dp[cur][remain-1];
                if(cur>0) res=(res+dp[cur-1][remain-1])%mod;
                if(cur<arrLen-1) res=(res+dp[cur+1][remain-1])%mod;
                dp[cur][remain]=res;
            }
        }
        return dp[0][steps];
    }
};