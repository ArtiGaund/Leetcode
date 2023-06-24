class Solution {
public:
    int tallestBillboard(vector<int>& rods) {
        int sum=0;
        for(auto r:rods) sum+=r;
        vector<int> dp(sum+1,-1);
        dp[0]=0;
        for(int r:rods)
        {
            vector<int> temp(sum+1);
            temp=dp;
            for(int i=0;i<=sum;i++)
            {
                if(temp[i]<0) continue;
                dp[i+r]=max(dp[i+r],temp[i]);
                dp[abs(i-r)]=max(dp[abs(i-r)],temp[i]+min(i,r));
            }
        }
        return dp[0];
    }
};