class Solution {
public:
    int m,n;
    int numIslands(vector<vector<char>>& grid) {
        m=grid.size();
        n=grid[0].size();
        int island=0;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]=='1')
                {
                    island++;
                    dfs(i,j,grid);
                }
            }
        }
        return island;
    }
    void dfs(int row,int col,vector<vector<char>> &grid)
    {
       if(row<0 or row>=m or col<0 or col>=n or grid[row][col]!='1') return;
        grid[row][col]='*';
        dfs(row-1,col,grid);
        dfs(row+1,col,grid);
        dfs(row,col-1,grid);
        dfs(row,col+1,grid);
    }
};