class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        int r=grid.size();
        int c=grid[0].size();
        if(grid[0][0]==1) return 0;
        grid[0][0]=1;
        for(int i=1;i<r;i++)
            grid[i][0]=(grid[i][0]==0 and grid[i-1][0]==1)?1:0;
        for(int j=1;j<c;j++)
            grid[0][j]=(grid[0][j]==0 and grid[0][j-1]==1)?1:0;
        for(int i=1;i<r;i++)
        {
            for(int j=1;j<c;j++)
            {
                if(grid[i][j]==0) grid[i][j]=grid[i-1][j]+grid[i][j-1];
                else grid[i][j]=0;
            }
        }
        return grid[r-1][c-1];
    }
};