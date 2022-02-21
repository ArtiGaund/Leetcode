class Solution {
public:
    int m,n;
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        m=grid.size();
        n=grid[0].size();
        if(m==0) return 0;
        int max_area=0;
        int island=0;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==1)
                {
                    island=0;
                    dfs(grid,i,j,island);
                    max_area=max(max_area,island);
                }
            }
        }
        return max_area;
    }
    void dfs(vector<vector<int>> &grid,int r,int c,int &island)
    {
        if(r<0 or r>=m or c<0 or c>=n or grid[r][c]!=1) return;
        island++;
        grid[r][c]=0;
        dfs(grid,r-1,c,island);
        dfs(grid,r+1,c,island);
        dfs(grid,r,c-1,island);
        dfs(grid,r,c+1,island);
    }
};