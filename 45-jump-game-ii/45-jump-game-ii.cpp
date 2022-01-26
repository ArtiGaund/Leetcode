class Solution {
public:
    int jump(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n,0);
        for(int i=1;i<n;i++) dp[i]=INT_MAX;
        for(int start=0;start<n-1;start++)
        {
            for(int end=start+1;end<=start+nums[start] and end<n;end++)
                dp[end]=min(dp[end],dp[start]+1);
        }
        return dp[n-1];
    }
};