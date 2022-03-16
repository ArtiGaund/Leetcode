class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n,-1);
        return solve(nums,dp,0);
    }
    int solve(vector<int> &nums,vector<int> &dp,int i)
    {
        if(i>=nums.size()) return 0;
        if(dp[i]!=-1) return dp[i];
        int step1=nums[i]+solve(nums,dp,i+2);
        int step2=solve(nums,dp,i+1);
        dp[i]=max(step1,step2);
        return dp[i];
    }
};