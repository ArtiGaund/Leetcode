class Solution {
public:
    void dfs(vector<vector<char>> &grid,int i,int j)
    {
        if(i<0 or i>=grid.size() or j<0 or j>=grid[0].size() or grid[i][j]!='1') return;
        grid[i][j]='2';
        dfs(grid,i-1,j);
        dfs(grid,i+1,j);
        dfs(grid,i,j-1);
        dfs(grid,i,j+1);
    }
    int numIslands(vector<vector<char>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        // vector<vector<bool>> vis(m,vector<bool>(n,0));
        int ans=0;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]=='1')
                {
                    dfs(grid,i,j);
                    ans++;
                }
            }
        }
        return ans;
    }
};