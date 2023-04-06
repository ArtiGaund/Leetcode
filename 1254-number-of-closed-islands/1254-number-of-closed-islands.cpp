class Solution {
public:
    bool isOnPerimeter(int i,int j,int m,int n)
    {
        return (i==0 or j==0 or i==m-1 or j==n-1);
    }
    bool dfs(vector<vector<int>> &grid,int i,int j,int m,int n)
    {
        if(grid[i][j]==-1 or grid[i][j]==1) return true;
        if(isOnPerimeter(i,j,m,n)) return false;
        grid[i][j]=-1;
        int up=dfs(grid,i-1,j,m,n);
        int down=dfs(grid,i+1,j,m,n);
        int left=dfs(grid,i,j-1,m,n);
        int right=dfs(grid,i,j+1,m,n);
        return (left and right and up and down);
    }
    int closedIsland(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        int island=0;
        for(int i=1;i<m-1;i++)
        {
            for(int j=1;j<n-1;j++)
            {
                if(grid[i][j]==0)
                {
                    if(dfs(grid,i,j,m,n)) island++;
                }
            }
        }
        return island;
    }
    
};