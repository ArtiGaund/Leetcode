class Solution {
public:
    int getIslandSize(vector<vector<int>> &grid,int i,int j,int m,int n,int island)
    {
        if(i<0 or i>=m or j<0 or j>=n or grid[i][j]!=1) return 0;
        grid[i][j]=island;
        int left=getIslandSize(grid,i,j-1,m,n,island);
        int right=getIslandSize(grid,i,j+1,m,n,island);
        int up=getIslandSize(grid,i-1,j,m,n,island);
        int down=getIslandSize(grid,i+1,j,m,n,island);
        return left+right+up+down+1;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m=grid.size(),n=grid[0].size();
        if(m==0 or n==0) return 0;
        int maxarea=0,island=2;
        // unordered_map<int,int> mp;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==1)
                {
                    int size=getIslandSize(grid,i,j,m,n,island);
                    maxarea=max(size,maxarea);
                    // mp[island]=size;
                    island++;
                }
            }
        }
        return maxarea;
    }
};