class Solution {
public:
    int n,m;
    int ans=0;
    int numIslands(vector<vector<char>>& grid) {
        n=grid.size();
        m=grid[0].size();
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
    void dfs(vector<vector<char>> &v,int i,int j)
    {
        if(i<0 or i>=n or j<0 or j>=m or v[i][j]!='1') return;
        v[i][j]='*';
        dfs(v,i-1,j);
        dfs(v,i+1,j);
        dfs(v,i,j-1);
        dfs(v,i,j+1);
    }
};