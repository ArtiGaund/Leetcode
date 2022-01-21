class Solution {
public:
    int jump(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n);
        for(int i=1;i<n;i++) dp[i]=INT_MAX;
        for(int start=0;start<n;start++)
        {
            for(int end=start+1;end<n and end<=start+nums[start];end++)
                dp[end]=min(dp[end],dp[start]+1);
        }
        return dp[n-1];
    }
};