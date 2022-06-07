class Solution {
public:
    int solve(int index,vector<int> &num,int k,vector<int> &dp)
{
    int n=num.size();
    if(index==n) return 0;
    if(dp[index]!=-1) return dp[index];
    int len=0;
    int maxi=INT_MIN;
    int res=INT_MIN;
    for(int j=index;j<min(index+k,n);j++)
    {
        len++;
        maxi=max(maxi,num[j]);
        int sum=len*maxi+solve(j+1,num,k,dp);
        res=max(res,sum);
    }
    return dp[index]=res;
}
    int maxSumAfterPartitioning(vector<int>& nums, int k) {
       int n=nums.size();
    vector<int> dp(n,-1);
    return solve(0,nums,k,dp);
    }
};