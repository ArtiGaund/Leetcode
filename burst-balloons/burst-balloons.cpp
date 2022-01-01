class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int n=nums.size();
        vector<int> B(n+2);
        B[0]=1;
        B[n+1]=1;
        for(int i=1;i<=n;i++)
            B[i]=nums[i-1];
        vector<vector<int>> dp(n+2,vector<int>(n+2,0));
        for(int len=1;len<n+1;len++)
        {
            for(int left=1;left<n-len+2;left++)
            {
                int right=left+len-1;
                for(int last=left;last<right+1;last++)
                    dp[left][right]=max(dp[left][right],dp[left][last-1]+B[left-1]*B[last]*B[right+1]+dp[last+1][right]);
            }
        }
        return dp[1][n];
    }
};