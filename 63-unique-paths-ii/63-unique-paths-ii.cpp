class Solution {
public:
    int mod=(int)(1e9+7);
   
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        int r=grid.size();
        int c=grid[0].size();
        for(int i=0;i<r;i++)
        {
            for(int j=0;j<c;j++)
            {
                if(grid[i][j]==1)
                    grid[i][j]=-1;
            }
        }
        vector<vector<int>> dp(r,vector<int>(c,-1));
       for(int i=0;i<r;i++)
       {
           for(int j=0;j<c;j++)
           {
               if(grid[i][j]==-1) dp[i][j]=0;
               else if(i==0 and j==0) dp[i][j]=1;
               else 
               {
                   int up=0,left=0;
                   if(i>0) up=dp[i-1][j];
                   if(j>0) left=dp[i][j-1];
                   dp[i][j]=(up+left);
               }
           }
       }
        return dp[r-1][c-1];
    }
};