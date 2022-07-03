class Solution {
public:
    int m,n;
    bool is_valid(int i,int j,vector<vector<int>> &grid,int color)
    {
        return (i>=0 and i<m and j>=0 and j<n and grid[i][j]==color and grid[i][j]>0);
    }
    bool is_colorable(int i,int j,vector<vector<int>> &grid,int color)
    {
        if(i==0 or j==0 or i==m-1 or j==n-1) return true;
        if(i-1>=0 and abs(grid[i-1][j])!=color and grid[i-1][j]!=1e9) return true;
        if(i+1<m and abs(grid[i+1][j])!=color and grid[i+1][j]!=1e9) return true;
        if(j-1>=0 and abs(grid[i][j-1])!=color and grid[i][j-1]!=1e9) return true;
        if(j+1<n and abs(grid[i][j+1])!=color and grid[i][j+1]!=1e9) return true;
        return false;
    }
    void dfs(vector<vector<int>> &grid,int i,int j,int color)
    {
        if(!is_valid(i,j,grid,color)) return;
        if(is_colorable(i,j,grid,color)) grid[i][j]=1e9;
        else grid[i][j]=-grid[i][j];
        dfs(grid,i-1,j,color);
        dfs(grid,i+1,j,color);
        dfs(grid,i,j-1,color);
        dfs(grid,i,j+1,color);
        if(grid[i][j]<0) grid[i][j]=-grid[i][j];
    }
    vector<vector<int>> colorBorder(vector<vector<int>>& grid, int row, int col, int color) {
        m=grid.size();
        n=grid[0].size();
        dfs(grid,row,col,grid[row][col]);
        for(auto &it:grid)
        {
            for(auto &i:it)
                if(i==1e9) i=color;
        }
        return grid;
    }
};