class Solution {
public:
    int dfs(vector<vector<int>> &matrix,vector<vector<int>> &dp,int m,int n,int i,int j)
    {
        if(dp[i][j]>0) return dp[i][j];
        int maxlen=0;
        vector<pair<int,int>> dir={{-1,0},{0,-1},{1,0},{0,1}};
        for(auto d:dir)
        {
            int x=i+d.first;
            int y=j+d.second;
            if(x>=0 and x<m and y>=0 and y<n and matrix[x][y]>matrix[i][j])
            {
                int longest=dfs(matrix,dp,m,n,x,y);
                maxlen=max(maxlen,longest);
            }
        }
        dp[i][j]=maxlen+1;
        return dp[i][j];
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int m=matrix.size(),n=matrix[0].size();
        if(m==0 or n==0) return 0;
        vector<vector<int>> dp(m,vector<int>(n,0));
        int maxlen=0;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                int longest=dfs(matrix,dp,m,n,i,j);
                maxlen=max(maxlen,longest);
            }
        }
        return maxlen;
    }
};