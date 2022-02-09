class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        vector<vector<int>> dp(n,vector<int>(m,-1));
        int mini=INT_MAX;
        for(int j=0;j<m;j++)
        {
            int ans=solve(n-1,j,dp,matrix,m);
            mini=min(mini,ans);
        }
        return mini;
    }
    int solve(int i,int j,vector<vector<int>> &dp,vector<vector<int>> &mat,int m)
    {
        if(j<0 or j>=m) return 1e9;
        if(i==0) return mat[0][j];
        if(dp[i][j]!=-1) return dp[i][j];
        int up=mat[i][j]+solve(i-1,j,dp,mat,m);
        int left=mat[i][j]+solve(i-1,j-1,dp,mat,m);
        int right=mat[i][j]+solve(i-1,j+1,dp,mat,m);
        return dp[i][j]=min({up,left,right});
    }
};