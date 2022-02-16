class Solution {
public:
    int m,n;
    int maxPath;
    vector<vector<int>> dir={{0,-1},{-1,0},{1,0},{0,1}};
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        m=matrix.size();
        n=matrix[0].size();
        vector<vector<int>> dp(m,vector<int>(n,-1));
        maxPath=0;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
                maxPath=max(maxPath,dfs(matrix,dp,i,j));
        }
        return maxPath;
    }
    int dfs(vector<vector<int>> &mat,vector<vector<int>> &dp,int i,int j)
    {
        if(dp[i][j]!=-1) return dp[i][j];
        dp[i][j]=1;
        for(int d=0;d<4;d++)
        {
            int new_i=i+dir[d][0];
            int new_j=j+dir[d][1];
            if(new_i<0 or new_i>=m or new_j<0 or new_j>=n or mat[new_i][new_j]<=mat[i][j]) continue;
            dp[i][j]=max(dp[i][j],1+dfs(mat,dp,new_i,new_j));
        }
        return dp[i][j];
    }
};