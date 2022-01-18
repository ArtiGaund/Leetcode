class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum=accumulate(nums.begin(),nums.end(),0);
        if(sum%2) return false;
        int halfsum=sum/2;
        vector<bool> dp(halfsum+1,false);
        dp[0]=true;
        for(int a:nums)
        {
            for(int j=halfsum;j>=a;j--)
            {
                if(dp[j-a]) dp[j]=true;
            }
        }
        return dp[halfsum];
    }
};