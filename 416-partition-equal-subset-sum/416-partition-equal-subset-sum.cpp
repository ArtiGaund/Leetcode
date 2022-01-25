class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum=accumulate(nums.begin(),nums.end(),0);
        if(sum%2!=0) return false;
        int n=nums.size();
        int halfsum=sum/2;
        vector<int> dp(halfsum+1,-1);
        return solve(dp,nums,halfsum,0);
    }
    bool solve(vector<int> &dp,vector<int> &v,int sum,int i)
    {
        if(sum==0) return true;
        if(sum<0 or i>=v.size()) return false;
        if(dp[sum]!=-1) return dp[sum];
        dp[sum]=(solve(dp,v,sum-v[i],i+1) or solve(dp,v,sum,i+1));
        return dp[sum];
    }
};