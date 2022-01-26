class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==0) return 0;
        if(n==1) return nums[0];
        if(n==2) return max(nums[0],nums[1]);
        int res1=solve(nums,0,n-2);
        int res2=solve(nums,1,n-1);
        return max(res1,res2);
    }
    int solve(vector<int> &nums,int start,int end)
    {
        if(start==end) return nums[start];
        int n=nums.size();
        vector<int> dp(n);
        dp[start]=nums[start];
        dp[start+1]=max(nums[start],nums[start+1]);
        for(int i=start+2;i<=end;i++)
            dp[i]=max(dp[i-1],dp[i-2]+nums[i]);
        return dp[end];
    }
};