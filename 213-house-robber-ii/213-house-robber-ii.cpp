class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return nums[0];
        if(n==2) return max(nums[0],nums[1]);
        int res1=solve(nums,0,n-2);
        int res2=solve(nums,1,n-1);
        return max(res1,res2);
    }
    int solve(vector<int> &nums,int s,int e)
    {
        if(s==e) return nums[s];
        vector<int> dp(nums.size());
        dp[s]=nums[s];
        dp[s+1]=max(nums[s],nums[s+1]);
        for(int i=s+2;i<=e;i++)
            dp[i]=max(dp[i-1],dp[i-2]+nums[i]);
        return dp[e];
    }
};