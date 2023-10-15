class Solution {
public:
    int numWays(int steps, int arrLen) {
        int mod=1e9+7;
        arrLen=min(arrLen,steps);
        vector<int> dp(arrLen,0);
        vector<int> prev(arrLen,0);
        prev[0]=1;
        for(int remain=1;remain<=steps;remain++)
        {
            dp=vector(arrLen,0);
            for(int cur=arrLen-1;cur>=0;cur--)
            {
                int res=prev[cur];
                if(cur>0) res=(res+prev[cur-1])%mod;
                if(cur<arrLen-1) res=(res+prev[cur+1])%mod;
                dp[cur]=res;
            }
            prev=dp;
        }
        return dp[0];
    }
};