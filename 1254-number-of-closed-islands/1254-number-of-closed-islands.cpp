class Solution {
public:
    bool isOnPerimeter(int i,int j,int rows,int cols)
    {
        return (i==0 or j==0 or i==rows-1 or j==cols-1);
    }
    bool isClosedIsland(vector<vector<int>> &grid,int i,int j,int rows,int cols)
    {
        // -1= visited, 1=water, 0= land
        if(grid[i][j]==-1 or grid[i][j]==1) return true;
        if(isOnPerimeter(i,j,rows,cols)) return false;
        grid[i][j]=-1;
        // check directions
        bool left=isClosedIsland(grid,i,j-1,rows,cols);
         bool right=isClosedIsland(grid,i,j+1,rows,cols);
         bool up=isClosedIsland(grid,i-1,j,rows,cols);
         bool down=isClosedIsland(grid,i+1,j,rows,cols);
        return (left and right and up and down);
    }
    int closedIsland(vector<vector<int>>& grid) {
        int rows=grid.size();
        int cols=grid[0].size();
        if(rows==0 or cols==0) return 0;
        int closedIsland=0;
        for(int i=1;i<rows-1;i++)
        {
            for(int j=1;j<cols-1;j++)
            {
                if(grid[i][j]==0)
                {
                    if(isClosedIsland(grid,i,j,rows,cols))
                        closedIsland++;
                }
            }
        }
        return closedIsland;
    }
};