class Solution {
public:
    int n;
    vector<pair<int,int>> dir={{-1,0},{0,-1},{1,0},{0,1}};
    bool solve(vector<vector<int>> &grid,bool vis[][50],int i,int j,int w_lvl)
    {
        if(i<0 or i>=n or j<0 or j>=n or vis[i][j] or grid[i][j]>w_lvl) return false;
        if(i==n-1 and j==n-1) return true;
        vis[i][j]=1;
        for(auto d:dir)
            if(solve(grid,vis,i+d.first,j+d.second,w_lvl)) return true;
        return false;
    }
    int swimInWater(vector<vector<int>>& grid) {
        n=grid.size();
        int l=max({2*(n-1),grid[0][0],grid[n-1][n-1]});
        int r=n*n-1;
        int mid;
        bool vis[50][50]={{0}};
        while(l<=r)
        {
            mid=(l+r)/2;
            if(solve(grid,vis,0,0,mid))
                r=mid-1;
            else l=mid+1;
            memset(vis,false,sizeof(vis));
        }
        return l;
    }
};