class Solution {
public:
    bool solve(vector<int> &nums,int sum,int curIndex,vector<vector<int>> &dp)
    {
        if(sum==0) return true;
        if(nums.empty() or curIndex>=nums.size()) return false;
        if(dp[curIndex][sum]==-1)
        {
             if(nums[curIndex]<=sum)
             {
                  if(solve(nums,sum-nums[curIndex],curIndex+1,dp))
                  {
                      dp[curIndex][sum]=1;
                      return true;
                  }
             }
            dp[curIndex][sum]=(solve(nums,sum,curIndex+1,dp)?1:0);
           
        }
                               
       
        return (dp[curIndex][sum]==1?true:false);
    }
    bool canPartition(vector<int>& nums) {
        int sum=0;
        for(auto a:nums) sum+=a;
        if(sum%2!=0) return false;
        int n=nums.size();
        sum=sum/2;
        vector<vector<int>> dp(n,vector<int>(sum+1,-1));
        return solve(nums,sum,0,dp);
    }
};