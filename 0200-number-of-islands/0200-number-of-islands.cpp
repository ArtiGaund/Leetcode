class Solution {
public:
    int n,m;
    void dfs(vector<vector<char>> &grid,int row,int col)
    {
        if(row<0 or row>=n or col<0 or col>=m or grid[row][col]!='1') return;
        grid[row][col]='*';
        dfs(grid,row-1,col);
        dfs(grid,row+1,col);
        dfs(grid,row,col-1);
        dfs(grid,row,col+1);
    }
    int numIslands(vector<vector<char>>& grid) {
        n=grid.size();
        m=grid[0].size();
        int count=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]=='1')
                {
                    count++;
                    dfs(grid,i,j);
                }
            }
        }
        return count;
    }
};