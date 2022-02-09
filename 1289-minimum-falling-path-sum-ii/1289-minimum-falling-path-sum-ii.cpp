class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& grid) {
        int n=grid.size();
        int res=INT_MAX;
        vector<vector<int>> dp(n,vector<int>(n,INT_MAX));
        for(int j=0;j<n;j++)
            dp[0][j]=grid[0][j];
        for(int i=1;i<n;i++)
        {
            //case 1
            int mi=INT_MAX-200;
            for(int j=0;j<n;j++) //came from above from above row to cur
            {
                dp[i][j]=min(dp[i][j],mi+grid[i][j]);
                mi=min(dp[i-1][j],mi);
            }
            //case 2
            mi=INT_MAX-200;
            for(int j=n-1;j>=0;j--) //get min while coming from back side from above row to cu
            {
                dp[i][j]=min(dp[i][j],mi+grid[i][j]);
                mi=min(dp[i-1][j],mi);
            }
        }
        for(int j=0;j<n;j++)
            res=min(res,dp[n-1][j]);
        return res;
    }
};