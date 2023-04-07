class Solution {
public:
    int n,m;
    void dfs(vector<vector<int>> &vis,vector<vector<int>> &grid,int r,int c)
    {
        vis[r][c]=1;
        if(r>0 and grid[r-1][c]==1 and !vis[r-1][c])
            dfs(vis,grid,r-1,c);
        if(r<n-1 and grid[r+1][c]==1 and !vis[r+1][c])
            dfs(vis,grid,r+1,c);
        if(c>0 and grid[r][c-1]==1 and !vis[r][c-1])
            dfs(vis,grid,r,c-1);
        if(c<m-1 and grid[r][c+1] and !vis[r][c+1])
            dfs(vis,grid,r,c+1);
    }
    int numEnclaves(vector<vector<int>>& grid) {
        n=grid.size();
        m=grid[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(i==0 or i==n-1 or j==0 or j==m-1)
                {
                    if(!vis[i][j] and grid[i][j]==1)
                        dfs(vis,grid,i,j);
                }
            }
        }
        int count=0;
        for(int i=1;i<n;i++)
        {
            for(int j=1;j<m;j++)
            {
                if(!vis[i][j] and grid[i][j]==1)
                    count++;
            }
        }
        return count;
    }
};