class Solution {
public:
    int r,c;
    int orangesRotting(vector<vector<int>>& grid) {
        r=grid.size();
        c=grid[0].size();
        for(int i=0;i<r;i++)
        {
            for(int j=0;j<c;j++)
            {
                if(grid[i][j]==2)
                    dfs(grid,i,j,0,true);
            }
        }
        int res=0;
        for(int i=0;i<r;i++)
        {
            for(int j=0;j<c;j++)
            {
                if(grid[i][j]==1) return -1;
                res=max(abs(grid[i][j]),res);
            }
        }
        return res;
    }
    void dfs(vector<vector<int>> &grid,int x,int y,int count,bool start)
    {
        if(x<0 || x>=r || y<0 || y>=c || grid[x][y]==0|| grid[x][y]<0 && -grid[x][y]<count )
            return;
        if(grid[x][y]==2 && !start)
            return;
            
        grid[x][y]=-count;
        
        dfs(grid,x+1,y,count+1,false);
        dfs(grid,x,y+1,count+1,false);
        dfs(grid,x-1,y,count+1,false);
        dfs(grid,x,y-1,count+1,false);
    }
};