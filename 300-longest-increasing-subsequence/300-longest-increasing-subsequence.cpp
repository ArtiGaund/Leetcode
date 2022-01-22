class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n);
        dp[0]=1;
        int maxlen=1;
        for(int i=1;i<n;i++)
        {
            dp[i]=1;
            for(int j=0;j<i;j++)
            {
                if(nums[i]>nums[j] and dp[i]<=dp[j])
                {
                    dp[i]=dp[j]+1;
                    maxlen=max(dp[i],maxlen);
                }
            }
        }
        return maxlen;
    }
};