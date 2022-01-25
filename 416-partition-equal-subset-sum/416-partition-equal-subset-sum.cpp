class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum=accumulate(nums.begin(),nums.end(),0);
        if(sum%2!=0) return false;
        int n=nums.size();
        int halfsum=sum/2;
        vector<vector<int>> dp(n,vector<int>(halfsum+1,-1));
        return solve(dp,nums,halfsum,0);
    }
    bool solve(vector<vector<int>> &dp,vector<int> &v,int sum,int i)
    {
        if(sum==0) return true;
        if(sum<0 or i>=v.size()) return false;
        if(dp[i][sum]!=-1) return dp[i][sum];
        dp[i][sum]=(solve(dp,v,sum-v[i],i+1) or solve(dp,v,sum,i+1));
        return dp[i][sum];
    }
};