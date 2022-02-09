class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> dp(n,vector<int>(m,-1));
        return solve(n-1,m-1,dp,grid);
    }
    int solve(int i,int j,vector<vector<int>> &dp,vector<vector<int>> &mat)
    {
        if(i==0 and j==0) return mat[0][0];
        if(i<0 or j<0) return 1e9;
        if(dp[i][j]!=-1) return dp[i][j];
        int up=mat[i][j]+solve(i-1,j,dp,mat);
        int left=mat[i][j]+solve(i,j-1,dp,mat);
        return dp[i][j]=min(up,left);
    }
};