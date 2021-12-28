class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        if(nums.size()==0) return {};
        int n=nums.size();
        vector<int> dp(n);
        dp[0]=1;
        for(int i=1;i<n;i++)
            dp[i]=dp[i-1]*nums[i-1];
        int t=1;
        for(int i=n-1;i>=0;i--)
        {
            dp[i]=dp[i]*t;
            t*=nums[i];
        }
        return dp;
    }
};