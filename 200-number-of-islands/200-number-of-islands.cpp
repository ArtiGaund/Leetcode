class Solution {
public:
    void dfs(vector<vector<char>> &grid,int i,int j,int m,int n)
    {
        if(i<0 or i>=m or j<0 or j>=n or grid[i][j]!='1') return;
        grid[i][j]='0';
        dfs(grid,i-1,j,m,n);
        dfs(grid,i+1,j,m,n);
        dfs(grid,i,j-1,m,n);
        dfs(grid,i,j+1,m,n);
    }
    int numIslands(vector<vector<char>>& grid) {
        int island=0;
        int m=grid.size();
        int n=grid[0].size();
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]=='1')
                {
                    island++;
                    dfs(grid,i,j,m,n);
                }
            }
        }
        return island;
    }
};