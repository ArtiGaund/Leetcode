class Solution {
public:
    int jump(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n,INT_MAX);
        dp[0]=0;
        for(int start=0;start<n-1;start++)
        {
            for(int end=start+1;end<=start+nums[start] and end<n;end++)
                dp[end]=min(dp[end],dp[start]+1);
        }
        return dp[n-1];
    }
};