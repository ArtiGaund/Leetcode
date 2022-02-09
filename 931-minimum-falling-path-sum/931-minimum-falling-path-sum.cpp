class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& A) {
        int n=A.size();
        int m=A[0].size();
        vector<vector<int>> dp(n,vector<int>(m,-1));
        int mini=INT_MAX;
        for(int j=0;j<m;j++)
        {
            int ans=solve(n-1,j,dp,A,m);
            mini=min(mini,ans);
        }
        return mini;
    }
    int solve(int i,int j,vector<vector<int>> &dp,vector<vector<int>> &A,int m)
    {
        if(j<0 or j>=m) return 1e9;
        if(i==0) return A[0][j];
        if(dp[i][j]!=-1) return dp[i][j];
        int up=A[i][j]+solve(i-1,j,dp,A,m);
        int leftdiagonal=A[i][j]+solve(i-1,j-1,dp,A,m);
        int rightdiagonal=A[i][j]+solve(i-1,j+1,dp,A,m);
        return dp[i][j]=min({up,leftdiagonal,rightdiagonal});
    }
};