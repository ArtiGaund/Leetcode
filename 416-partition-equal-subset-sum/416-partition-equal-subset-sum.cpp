class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n=nums.size();
        int sum=0;
        for(int a:nums) sum+=a;
        if(sum%2!=0) return false;
        sum/=2;
        vector<vector<bool>> dp(n,vector<bool>(sum+1));
        for(int i=0;i<n;i++) dp[i][0]=true;
        for(int j=0;j<=sum;j++) 
            dp[0][j]=(nums[0]==j?true:false);
        for(int i=1;i<n;i++)
        {
            for(int j=1;j<=sum;j++)
            {
                if(dp[i-1][j]) dp[i][j]=dp[i-1][j];
                else if(j>=nums[i]) dp[i][j]=dp[i-1][j-nums[i]];
            }
        }
        return dp[n-1][sum];
    }
};