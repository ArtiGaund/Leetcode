class Solution {
public:
    int n,m;
    int numIslands(vector<vector<char>>& grid) {
        n=grid.size();
        m=grid[0].size();
        int ans=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]=='1')
                {
                    ans++;
                    dfs(grid,i,j);
                }
            }
        }
        return ans;
    }
    void dfs(vector<vector<char>> &grid,int x,int y)
    {
        if(x<0 or x>=n or y<0 or y>=m or grid[x][y]!='1') return;
        grid[x][y]='*';
        dfs(grid,x+1,y);
        dfs(grid,x-1,y);
        dfs(grid,x,y+1);
        dfs(grid,x,y-1);
    }
};