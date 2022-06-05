class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>> dp(n+1,vector<int>(n+1,0));
        for(int index=n-1;index>=0;index--)
        {
            for(int prev=index-1;prev>=-1;prev--)
            {
                int len=0+dp[index+1][prev+1];
                if(prev==-1 or nums[index]>nums[prev])
                    len=max(len,1+dp[index+1][index+1]);
                dp[index][prev+1]=len;
            }
        }
        return dp[0][0];
    }
};