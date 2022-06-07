class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& nums, int k) {
       int n=nums.size();
    vector<int> dp(n+1,0);
    for(int index=n-1;index>=0;index--)
    {
        int len=0;
        int maxi=INT_MIN;
        int res=INT_MIN;
        for(int j=index;j<min(index+k,n);j++)
        {
            len++;
            maxi=max(maxi,nums[j]);
            int sum=len*maxi+dp[j+1];
            res=max(res,sum);
        }
        dp[index]=res;
    }
    return dp[0];
    }
};