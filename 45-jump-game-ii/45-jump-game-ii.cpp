class Solution {
public:
    int jump(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n,0);
        return solve(nums,dp,0);
    }
    int solve(vector<int> &nums,vector<int> &dp,int i)
    {
        if(i==nums.size()-1) return 0;
        if(nums[i]==0) return INT_MAX;
        if(dp[i]!=0) return dp[i];
        int total=INT_MAX;
        int start=i+1;
        int end=i+nums[i];
        while(start<nums.size() and start<=end)
        {
            int res=solve(nums,dp,start++);
            if(res!=INT_MAX)
                total=min(total,res+1);
        }
        dp[i]=total;
        return dp[i];
    }
};