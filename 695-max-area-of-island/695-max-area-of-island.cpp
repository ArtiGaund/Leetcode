class Solution {
public:
    int getIslandSize(vector<vector<int>> &grid,int i,int j,int islandId)
    {
        if(i<0 or i>=grid.size() or j<0 or j>=grid[0].size() or grid[i][j]!=1) return 0;
        grid[i][j]=islandId;
        int left=getIslandSize(grid,i,j-1,islandId);
        int right=getIslandSize(grid,i,j+1,islandId);
        int up=getIslandSize(grid,i-1,j,islandId);
        int down=getIslandSize(grid,i+1,j,islandId);
        return left+right+up+down+1;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m=grid.size(),n=grid[0].size();
        if(m==0 or n==0) return 0;
        int islandId=2;
        int maxArea=0;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==1)
                {
                    int size=getIslandSize(grid,i,j,islandId);
                    maxArea=max(maxArea,size);
                    islandId++;
                }
            }
        }
        return maxArea;
    }
};