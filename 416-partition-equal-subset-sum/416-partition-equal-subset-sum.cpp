class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum=accumulate(nums.begin(),nums.end(),0);
        if(sum%2) return false;
        int n=nums.size();
        int halfsum=sum/2;
        vector<int> dp(halfsum+1,-1);
        return solve(nums,dp,halfsum,0);
    }
    bool solve(vector<int> &v,vector<int> &dp,int sum,int i)
    {
        if(sum==0) return true;
        if(i>=v.size() or sum<0) return false;
        if(dp[sum]!=-1) return dp[sum];
        return dp[sum]=(solve(v,dp,sum-v[i],i+1) or solve(v,dp,sum,i+1));
    }
};