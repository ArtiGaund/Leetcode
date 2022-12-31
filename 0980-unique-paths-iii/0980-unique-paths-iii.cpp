class Solution {
public:
    int m,n;
    vector<pair<int,int>> dir={{-1,0},{0,-1},{1,0},{0,1}};
    bool isValid(int r,int c)
    {
        return (r>=0 and r<m and c>=0 and c<n);
    }
    int dfs(int r,int c,int left,pair<int,int> dest,vector<vector<int>> &grid)
    {
        if(left==-1 and pair<int,int>(r,c)==dest) return 1;
        grid[r][c]=-1;
        int ans=0;
        for(auto d:dir)
        {
            int x=r+d.first;
            int y=c+d.second;
            if(isValid(x,y) and grid[x][y]!=-1)
                ans+=dfs(x,y,left-1,dest,grid);
        }
        grid[r][c]=0;
        return ans;
    }
    int uniquePathsIII(vector<vector<int>>& grid) {
        m=grid.size();
        n=grid[0].size();
        pair<int,int> src,dest;
        int empty=0;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==0) empty++;
                if(grid[i][j]==1) src={i,j};
                if(grid[i][j]==2) dest={i,j};
            }
        }
        return dfs(src.first,src.second,empty,dest,grid);
    }
};