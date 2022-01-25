class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum=accumulate(nums.begin(),nums.end(),0);
        if(sum%2!=0) return false;
        int n=nums.size();
        int halfsum=sum/2;
       vector<vector<bool>> dp(n,vector<bool>(halfsum+1,false));
        for(int i=0;i<n;i++) dp[i][0]=true;
        for(int j=1;j<=halfsum;j++)
            dp[0][j]=(nums[0]==j?true:false);
        for(int i=1;i<n;i++)
        {
            for(int j=1;j<=halfsum;j++)
            {
                if(dp[i-1][j])
                    dp[i][j]=dp[i-1][j];
                else if(j>=nums[i])
                    dp[i][j]=dp[i-1][j-nums[i]];
            }
        }
        return dp[n-1][halfsum];
    }
   
};