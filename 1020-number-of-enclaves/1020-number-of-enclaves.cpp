class Solution {
public:
    int n,m;
    void dfs(int r,int c,vector<vector<int>> &grid,vector<vector<int>> &vis)
    {
        vis[r][c]=1;
        if(r>0 and !vis[r-1][c] and grid[r-1][c]==1)
            dfs(r-1,c,grid,vis);
        if(r<n-1 and !vis[r+1][c] and grid[r+1][c]==1)
            dfs(r+1,c,grid,vis);
        if(c>0 and !vis[r][c-1] and grid[r][c-1]==1)
            dfs(r,c-1,grid,vis);
        if(c<m-1 and !vis[r][c+1] and grid[r][c+1]==1)
            dfs(r,c+1,grid,vis);
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
                        dfs(i,j,grid,vis);
                }
            }
        }
        int count=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(!vis[i][j] and grid[i][j]==1)
                    count++;
            }
        }
        return count;
    }
};