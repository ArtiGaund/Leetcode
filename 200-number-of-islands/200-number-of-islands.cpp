class Solution {
public:
    //DFS
    int n,m,count=0;
    int numIslands(vector<vector<char>>& grid) {
        n=grid.size();
        m=grid[0].size();
        if(n==0) return 0;
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
    void dfs(vector<vector<char>> &grid,int i,int j)
    {
        if(i<0 or i>=n or j<0 or j>=m or grid[i][j]!='1') return;
        grid[i][j]='*';
        dfs(grid,i-1,j);
        dfs(grid,i+1,j);
        dfs(grid,i,j-1);
        dfs(grid,i,j+1);
    }
};