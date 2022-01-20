class Solution {
public:
    int jump(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n,0);
        return solve(dp,nums,0);
    }
    int solve(vector<int> &dp,vector<int> &nums,int i)
    {
        if(i==nums.size()-1) return 0;
        if(nums[i]==0) return INT_MAX;
        if(dp[i]!=0) return dp[i];
        int total=INT_MAX;
        int start=i+1;
        int end=i+nums[i];
        while(start<nums.size() and start<=end)
        {
            int minjump=solve(dp,nums,start++);
            if(minjump!=INT_MAX)
                total=min(total,minjump+1);
        }
        dp[i]=total;
        return dp[i];
    }
};