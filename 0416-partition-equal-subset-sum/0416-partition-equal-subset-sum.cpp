class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum=0;
        for(int a:nums) sum+=a;
        if(sum%2!=0) return false;
        int k=sum/2;
        int n=nums.size();
        vector<vector<int>> dp(n,vector<int>(k+1));
        if(k>=nums[0]) dp[0][nums[0]]=true;
        for(int index=1;index<n;index++)
        {
            for(int target=1;target<=k;target++)
            {
                int nottaken=dp[index-1][target];
                int taken=false;
                if(target>=nums[index]) taken=dp[index-1][target-nums[index]];
                dp[index][target]=(taken or nottaken);
            }
        }
        return dp[n-1][k];
    }
};